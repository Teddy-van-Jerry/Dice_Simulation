#include "ds_convert.h"

DS_Convert::DS_Convert() { }


DS_Convert::DS_Convert(QString sourceFile, QString destinationFile)
    : sourceFile_(sourceFile), destinationFile_(destinationFile) { }

bool DS_Convert::convert() {
    initConvert();
    readFileAll();
    if (lines_.empty()) return true;
    qDebug() << lines_; // debug
    int i = 0; // line number index, from 0 to lines_.size() - 1
    while (i < lines_.size()) {
        QString line_simplified = lines_.at(i).simplified();
        // Skip empty line.
        if (!line_simplified.isEmpty()) {
            // If contents are not inside # block, just ignore them.
            int index = 0; // index of the block type in blockDefPairs
            for (; index != blockDefPairs.size() && line_simplified != blockDefPairs.at(index).at(0); index++);
            if (index < blockDefPairs.size()) {
                int j = i + 1; // line number of the end block
                for (; j < lines_.size(); j++) {
                    QString line_simplified = lines_.at(j).simplified();
                    if (line_simplified == blockDefPairs.at(index).at(1)) break; // find match
                }
                if (j > lines_.size()) {
                    // ERROR: unclosed DS block
                    return false;
                }
                if (!convertDSBlock(index, i, j)) return false; // convert the block from line i to j
            }
        }
        i++;
    }
    return true;
}

void DS_Convert::setFiles(QString sourceFile, QString destinationFile) {
    sourceFile_      = sourceFile;
    destinationFile_ = destinationFile;
}

void DS_Convert::setDebug(bool debug) {
    debug_ = debug;
}

bool DS_Convert::initConvert() {
    QFile f(destinationFile_);
    if (f.open(QIODevice::WriteOnly)) {
        QTextStream out(&f);
        out << "// Converted by Dice Simulation " << __DS_VERSION_STR__
            << " at " << QDateTime::currentDateTimeUtc().toString("yyyy-MM-dd UTC") << ".\n" << Qt::endl;
        f.close();
        return true;
    } else {
        qDebug() << "Cannot write file " << destinationFile_ << Qt::endl;
        return false;
    }
}

bool DS_Convert::readFileAll() {
    QFile f(sourceFile_);
    if (f.open(QIODevice::ReadOnly)) {
        QTextStream in(&f);
        lines_.clear();
        while (!in.atEnd()) {
            QString line = in.readLine();
            lines_.push_back(line);
        }
        f.close();
    } else {
        qDebug() << "Cannot open file " << sourceFile_ << Qt::endl;
        return false;
    }
    removeComments(); // replace comments texts into spaces
    return true;
}

bool DS_Convert::writeLine(const QString& line) const {
    QFile f(destinationFile_);
    if (f.open(QIODevice::WriteOnly | QIODevice::Append)) {
        QTextStream out(&f);
        out << line << Qt::endl;
        f.close();
        return true;
    } else {
        qDebug() << "Cannot write file " << destinationFile_ << Qt::endl;
        return false;
    }
}

bool DS_Convert::writeLines(const QStringList& lines) const {
    QFile f(destinationFile_);
    if (f.open(QIODevice::WriteOnly | QIODevice::Append)) {
        QTextStream out(&f);
        for (const auto& line : lines) out << line << Qt::endl;
        f.close();
        return true;
    } else {
        qDebug() << "Cannot write file " << destinationFile_ << Qt::endl;
        return false;
    }
}

QString DS_Convert::convertVarDef(QString type, QString varName, const QString& value) const {
    return type + " " + varName + "=" + value + ";";
}

bool DS_Convert::removeComments() {
    int comment_row = 0; // the row that "/*" occurs
    int current_row = 0; // the current line number
    for (auto& line : lines_) {
        current_row++;
        if (line.length() < 2) {
            // no chance of being the beginning or end of comments
            // If inside multi-line comments, just clear it out.
            // But here ensures that it has length 1.
            if (comment_row) line.clear();
            line.push_back(' ');
            continue;
        }
        for (auto i = 0; i != line.length(); i++) {
            if (comment_row) {
                if (i + 1 == line.length()) {
                    line[i] = ' ';
                    break;
                }
                // finding the matching "*/"
                if (line[i] == '*' && line[i + 1] == '/') {
                    line[i] = line[i + 1] = ' ';
                    i++;
                    comment_row = 0;
                    continue;
                } else {
                    line[i] = ' ';
                }
            } else {
                // check if it is the beginning of comments
                if (i + 1 >= line.length()) break;
                if (line[i] != '/') continue;
                if (line[i + 1] == '/') {
                    // single-line comments
                    line = line.left(i); // from 0 to i - 1
                    break;
                } else if (line[i + 1] == '*') {
                    // multi-line comments
                    comment_row = current_row;
                    line[i] = line[i + 1] = ' ';
                }
            }
        }
    }
    // If comment_row is not set to 0,
    // there are unfinshed comments.
    if (comment_row) {
        // ERROR: Unfinished Comments
    }
    return !comment_row;
}

bool DS_Convert::convertDSBlock(int blockType, int begin_i, int end_i) {
    switch (blockType) {
    case 0:
        return convert_DS_GLOBAL(begin_i, end_i);
    default:
        return false;
    }
}

bool DS_Convert::convert_DS_GLOBAL(int begin_i, int end_i) {
    QStringList converted;
    QStringList includeConverted = {"#include \"ds_core.ds-h\""};
    int i = begin_i; // line number
    while (++i != end_i) {
        QString line = lines_.at(i);
        // Find the first occurence of the sybols
        // to avoid the problem of user employing these symbols in value defination.
        int _1 = line.indexOf(':'); // the division symbol after variable name
        if (_1 == -1) {
            // does not find ':', just skip this line
            // maybe WARNING or ERROR in the future
            // This should not trigger an error because this line can be empty.
            continue;
        }
        QString fieldName = line.left(_1).simplified().remove(QChar('\"')).toLower();
        QString varName = fieldName;
        QString value = line.mid(_1 + 1).trimmed();
        int _2 = line.indexOf('[', _1);
        // qDebug() << line.mid(_1 + 1, _2 - _1 - 1).trimmed();
        if (line.mid(_1 + 1, _2 - _1 - 1).trimmed().isEmpty()) {
            // This is indeed the start symbol of variable name (optional).
            int _3 = line.indexOf(']', _2); // the end symbol of variable name.
            if (_3 == -1) {
                // ERROR: unclosed '['
                return false;
            }
            varName = line.mid(_2 + 1, _3 - _2 - 1).simplified().remove(QChar('\"'));
            qDebug() << varName;
            value = line.mid(_3 + 1).trimmed();
        }

        qDebug() << fieldName;

        if (fieldName == "gravity") {
            converted.append("double " + varName + "=" + value + ";");
        } else if (fieldName == "include") {
            QStringList includeStatements = value.split(",;", Qt::SkipEmptyParts);
            for (const auto& s : includeStatements)  includeConverted.append("#include " + s);
        } else if (fieldName == "version") {
            converted.append("const char* " + varName + "=" + value + ";");
        }
    }
    converted.append("");
    includeConverted.append("");
    if (!writeLines(includeConverted)) return false;
    if (!writeLines(converted)) return false;
    return true;
}

bool DS_Convert::convert_DS_PROCESS(int begin_i, int end_i) {
    return true;
}

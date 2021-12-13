#include "ds_convert.h"

DS_Convert::DS_Convert() { }


DS_Convert::DS_Convert(QString sourceFile, QString destinationFile)
    : sourceFile_(sourceFile), destinationFile_(destinationFile) { }

bool DS_Convert::convert() {
    readFileAll();
    if (lines_.empty()) return true;
    qDebug() << lines_; // debug
    int i = 0; // line number index, from 0 to lines_.size() - 1
    while (i < lines_.size()) {
        QString line_simplified = lines_.at(i).simplified();
        // Skip empty line.
        if (!line_simplified.isEmpty()) {
            // If contents are not inside # block, just ignore them.
            if (line_simplified == "#DS_BEGIN_GLOBAL") {
                // TODO
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

void DS_Convert::readFileAll() {
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
    }
    removeComments(); // replace comments texts into spaces
}

void DS_Convert::writeLine(const QString& line) const {
    QFile f(destinationFile_);
    if (f.open(QIODevice::WriteOnly | QIODevice::Append)) {
        QTextStream out(&f);
        out << line << Qt::endl;
        f.close();
    } else {
        qDebug() << "Cannot write file " << destinationFile_ << Qt::endl;
    }
}

void DS_Convert::writeLines(const QStringList& lines) const {
    QFile f(destinationFile_);
    if (f.open(QIODevice::WriteOnly | QIODevice::Append)) {
        QTextStream out(&f);
        for (const auto& line : lines) out << line << Qt::endl;
        f.close();
    } else {
        qDebug() << "Cannot write file \"" << destinationFile_ << "\"" << Qt::endl;
    }
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

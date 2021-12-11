#include "ds_convert.h"

DS_Convert::DS_Convert() { }


DS_Convert::DS_Convert(QString sourceFile, QString destinationFile)
    : sourceFile_(sourceFile), destinationFile_(destinationFile) { }

bool DS_Convert::convert() {
    if (lines_.empty()) return true;
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
        qDebug() << "Cannot open file \"" << sourceFile_ << "\"" << Qt::endl;
    }
}

void DS_Convert::writeLine(const QString& line) const {
    QFile f(destinationFile_);
    if (f.open(QIODevice::WriteOnly | QIODevice::Append)) {
        QTextStream out(&f);
        out << line << Qt::endl;
        f.close();
    } else {
        qDebug() << "Cannot write file \"" << destinationFile_ << "\"" << Qt::endl;
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

#include <QCoreApplication>
#include <QCommandLineParser>
#include "global.h"
#include "ds_convert.h"

int main(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);
    QCoreApplication::setApplicationName("ds-convert");
    QCoreApplication::setApplicationVersion(__DS_CONVERT_VERSION_STR__);

    QCommandLineParser parser;
    parser.setApplicationDescription("Dice Simulation Convert");
    parser.addHelpOption();
    parser.addVersionOption();
    parser.addPositionalArgument("source", QCoreApplication::translate("main", "Dice Simulation source file (*.ds, *.ds-cpp) to convert."));
    parser.addPositionalArgument("destination", QCoreApplication::translate("main", "Destination file of the converted cpp file."));

    parser.addOptions({
        {{"d", "debug"},
            QCoreApplication::translate("main", "Convert in debug mode.")},
        // {{"I", "include"},
        //    QCoreApplication::translate("main", "Include path. (default: ../include)")},
        {{"s", "style"},
            QCoreApplication::translate("main", "Set the style for the converted file.")}
    });

    parser.process(a);

    // qDebug() << "Started" << Qt::endl;

    // https://doc-snapshots.qt.io/qt6-dev/qcommandlineparser.htm
    const QStringList args = parser.positionalArguments();

    // qDebug() << args.size() << Qt::endl;
    if (args.size() == 2) {
        QString sourceFile = args.at(0);
        QString destinationFile = args.at(1);
        DS_Convert convert(sourceFile, destinationFile);
        convert.setDebug(parser.isSet("debug"));
        if (convert.convert()) {

        } else {

        }
    }

    return 0;
}

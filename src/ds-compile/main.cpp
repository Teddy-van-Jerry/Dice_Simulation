#include <QCoreApplication>
#include <QCommandLineParser>
#include "global.h"
#include "ds_compile.h"

int main(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);
    QCoreApplication::setApplicationName("ds-compile");
    QCoreApplication::setApplicationVersion(__DS_COMPILE_VERSION_STR__);

    QCommandLineParser parser;
    parser.setApplicationDescription("Dice Simulation Compile");
    parser.addHelpOption();
    parser.addVersionOption();
    parser.addPositionalArgument("source", QCoreApplication::translate("main", "Dice Simulation source file (*.ds, *.ds-cpp) to compile or converted cpp file."));
    parser.addPositionalArgument("destination", QCoreApplication::translate("main", "Destination file of the executable."));

    parser.addOptions({
        {{"d", "debug"},
            QCoreApplication::translate("main", "Compiles in debug mode.")},
        {{"I", "include"},
            QCoreApplication::translate("main", "Include path (Already included: ../include).")},
        {{"c", "convert"},
            QCoreApplication::translate("main", "Keep converted cpp file in specified location.")},
        {{"s", "style"},
            QCoreApplication::translate("main", "Set the style for the converted file.")}
    });

    parser.process(a);

    qDebug() << "Started" << Qt::endl;

    // https://doc-snapshots.qt.io/qt6-dev/qcommandlineparser.htm
    const QStringList args = parser.positionalArguments();

    qDebug() << args.size() << Qt::endl;

    return 0;
}

#ifndef GLOBAL_H
#define GLOBAL_H

#include "ds_global.ds-h"
#include "ds_qt_utils.h"
#include <QFileInfo>
#include <QTextStream>
#include <QProcess>
#include <QCoreApplication>
#include <QFile>
#include <QDir>

/** String version of __DS_CONVERT_VERSION__. */
const QString __DS_CONVERT_VERSION_STR__ = versionNumber2String(__DS_CONVERT_VERSION__);

/** String version of __DS_VERSION__. */
const QString __DS_VERSION_STR__ = versionNumber2String(__DS_VERSION__);

#endif // GLOBAL_H

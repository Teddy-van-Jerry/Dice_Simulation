/**
 * @file ds-compile/global.h
 * @brief Global Include File for ds-compile.
 * @author Teddy van Jerry
 * @date 2021-12-17
 */

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

/** String version of __DS_COMPILE_VERSION__. */
const QString __DS_COMPILE_VERSION_STR__ = versionNumber2String(__DS_COMPILE_VERSION__);

/** String version of __DS_VERSION__. */
const QString __DS_VERSION_STR__ = versionNumber2String(__DS_VERSION__);

/**
 * @enum CompileType
 * @brief The Compiling Type
 */
enum class CompileType {
    DS,      ///< Compile ds file and remove intermediate cpp file.
    DS_KEEP, ///< Compile ds file and keep intermediate cpp file.
    CPP      ///< Compile converted file.
};

#endif // GLOBAL_H

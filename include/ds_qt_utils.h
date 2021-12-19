/**
 * @file ds_qt_utils.h
 * @brief Qt utility functions for global use
 *
 * @date 2021-12-15
 * @author Teddy van Jerry
 */

#ifndef DS_QT_UTILS_H
#define DS_QT_UTILS_H

#include <QString>

/**
 * @brief Convert number from 'int' to 'QString'
 *
 * @return The QString version of version number
 *         with the format "major.minor.patch"
 */
QString versionNumber2String(int v);

/**
 * Alias for 2D array of QString.
 * It is actually implemented using QVector<QString>,
 * but the size of 2 should be obeserved by the user.
 */
using QStringPair = QVector<QString>;

#endif // DS_QT_UTILS_H

/**
 * @brief Qt utility functions for global use
 *
 * @date 2021-12-11
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
QString versionNumber2String(int v) {
    if (v <= 0) return "0.0.0";
    int patch = v % 256;
    int minor = v / 256 % 256;
    int major = v / 256 / 256;
    return QString::number(major) + "."
         + QString::number(minor) + "."
         + QString::number(patch);
}

#endif // DS_QT_UTILS_H

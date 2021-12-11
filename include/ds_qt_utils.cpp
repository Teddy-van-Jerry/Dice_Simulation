#include "ds_qt_utils.h"

QString versionNumber2String(int v) {
    if (v <= 0) return "0.0.0";
    int patch = v % 256;
    int minor = v / 256 % 256;
    int major = v / 256 / 256;
    return QString::number(major) + "."
         + QString::number(minor) + "."
         + QString::number(patch);
}

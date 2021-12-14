#ifndef GLOBAL_H
#define GLOBAL_H

#include "ds_global.ds-h"
#include "ds_qt_utils.h"

/** String version of __DS_CONVERT_VERSION__. */
const QString __DS_CONVERT_VERSION_STR__ = versionNumber2String(__DS_CONVERT_VERSION__);

/** String version of __DS_VERSION__. */
const QString __DS_VERSION_STR__ = versionNumber2String(__DS_VERSION__);

/** Task call begin symbol. */
#define __DS_TASK_CALL_BEGIN__ "```"

/** Task call end symbol. */
#define __DS_TASK_CALL_END__   "```!"

#endif // GLOBAL_H

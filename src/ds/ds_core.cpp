/**
 * @file ds_core.dpp
 * @brief Implementation for ds_core.ds-h
 *
 * @date 2021-12-18
 * @version 0.0.1
 * @author Teddy van Jerry
 */

#include "ds_core.ds-h"

Quaternion ds::normalQuaternion(double x, double y, double z, double w) {
    if (fabs(x) < 1E-12 && fabs(y) < 1E-12 && fabs(z) < 1E-12 && fabs(w) < 1E-12) {
        return Quaternion::identity();
    } else {
        Quaternion q(x, y, z, w);
        q.normalize(); // normalize
        return q;
    }
}

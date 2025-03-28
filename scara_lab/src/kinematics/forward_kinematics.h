#ifndef FORWARD_KINEMATICS_H
#define FORWARD_KINEMATICS_H

#include "limits.h"

/**
 * move_scara_fk expects input as degrees
 */
int move_scara_fk(float, float, float*, float*);

#endif


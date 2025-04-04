#ifndef FORWARD_KINEMATICS_H
#define FORWARD_KINEMATICS_H

#include "limits.h"

/****************************************************************************************
* Function: scaraFK
*
* Description:
* This function will calculate the x,y coordinates given two joint angles.
*
* Inputs:
* ang1 - Angle of joint 1 in degrees.
* ang2 - Angle of joint 2 in degrees.
* toolX - The tool position along the x-axis. Pointer
* toolY - The tool position along the y-axis. Pointer
*
* Returns:
* inRange - (0) in range, (-1) out of range
*
*****************************************************************************************/
int calculate_scara_fk(float, float, float*, float*);

#endif


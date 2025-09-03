#ifndef INVERSE_KINEMATICS_H
#define INVERSE_KINEMATICS_H

#include <stdbool.h>
#include "handedness.h"


/****************************************************************************************
* Function: scaraIK
*
* Description:
* This function will calculate two joint angles given the x,y coordinates.
*
* Inputs:
* toolX - The tool position along the x-axis.
* toolY - The tool position along the y-axis.
* ang1 - Angle of joint 1 in degrees. Pointer
* ang2 - Angle of joint 2 in degrees. Pointer
* arm - Selects which solution to try.
*
* Returns:
* inRange
*
*****************************************************************************************/
bool calculate_scara_ik(float, float, float*, float*, Handedness);

#endif


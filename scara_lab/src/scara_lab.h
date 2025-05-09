#ifndef SCARA_LAB_H
#define SCARA_LAB_H

#include <stdbool.h>

#include "kinematics.h"

typedef struct ScaraRobot {
	double theta_1;
	double theta_2;
	bool is_pen_down;
	Handedness handedness;
} ScaraRobot;

ScaraRobot new_scara_robot();
Coordinate current_coordinate();

#endif

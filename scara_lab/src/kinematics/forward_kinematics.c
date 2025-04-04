#include <stdlib.h>
#include <math.h>

#include "forward_kinematics.h"


int calculate_scara_fk(
	float angle1, float angle2, 
	float* x_position, float* y_position
) {
	if (abs(angle1) > MAX_ANGLE_1) {
		//TODO : Replace this int with a meaningful enum
		return 1;
	}
	if (abs(angle2) > MAX_ANGLE_2) {
		return 2;
	}


	float angle1_radians = angle1 * (M_PI / 180.0);
	float angle2_radians = (angle1 + angle2) * (M_PI / 180.0);

	float x1 = ARM_LENGTH_1 * cos(angle1_radians);
	float y1 = ARM_LENGTH_1 * sin(angle1_radians);

	float x2 = ARM_LENGTH_2 * cos(angle2_radians);
	float y2 = ARM_LENGTH_2 * sin(angle2_radians);

	*x_position = x1 + x2;
	*y_position = y1 + y2;

	return 0;
}

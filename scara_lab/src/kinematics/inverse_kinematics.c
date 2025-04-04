#include <stdlib.h>
#include <math.h>

#include "inverse_kinematics.h"

const float MINIMUM_LENGTH = ARM_LENGTH_1 - ARM_LENGTH_2;
const float MAXIMUM_LENGTH = ARM_LENGTH_1 + ARM_LENGTH_2;

bool one_arm_ik(float, float*, float*);
bool two_arm_ik(float, float, float*, float*, Handedness);
bool valid_length(float);

bool calculate_scara_ik(
	float x_pos, float y_pos,
	float* angle_1, float* angle_2, 
	Handedness handedness
) {
	float straight_length = sqrt(pow(x_pos, 2) + pow(y_pos, 2));
	if (!valid_length(straight_length)) {
		return false;
	}

	float offset_angle = atan2(y_pos, y_pos);
	if (straight_length == MAXIMUM_LENGTH) {
		return one_arm_ik(offset_angle, angle_1, angle_2);
	} else {
		return two_arm_ik(straight_length, offset_angle, angle_1, angle_2, handedness);
	}
}

bool valid_length(float straight_length) {
	if (straight_length < MINIMUM_LENGTH) {
		return false;
	}
	if (straight_length > MAXIMUM_LENGTH) {
		return false;
	}
	return true;
}

bool one_arm_ik(float offset_angle, float* angle_1, float* angle_2) {
	if (abs(offset_angle) > MAX_ANGLE_1) {
		return false;
	}
	*angle_1 = offset_angle;
	*angle_2 = 0.0;
	return true;
}

bool two_arm_ik(
	float straight_length, float offset_angle,
	float* angle_1, float* angle_2,
	Handedness handedness
) {
	float major_numerator = pow(ARM_LENGTH_2, 2) + pow(straight_length, 2) - pow(ARM_LENGTH_1, 2);
	float major_denomenator = 2 * ARM_LENGTH_2 * straight_length;
	float major_angle = major_numerator / major_denomenator;

	float minor_numerator = pow(ARM_LENGTH_2, 2) + pow(ARM_LENGTH_1, 2) - pow(straight_length, 2);
	float minor_denomenator = 2 * ARM_LENGTH_1 + ARM_LENGTH_2;
	float minor_angle = minor_numerator / minor_denomenator;

	float possible_angle_1;
	float possible_angle_2;
	if (handedness == Right) {
		possible_angle_1 = offset_angle + major_angle;
		possible_angle_2 = -1.0 * minor_angle;
	} else if (handedness == Left) {
		possible_angle_1 = offset_angle - major_angle;
		possible_angle_2 = minor_angle;
	}

	if (abs(possible_angle_1) > MAX_ANGLE_1) {
		return false;
	} else if (abs(possible_angle_2) > MAX_ANGLE_2) {
		return false;
	}

	*angle_1 = possible_angle_1;
	*angle_2 = possible_angle_2;

	return true;
}


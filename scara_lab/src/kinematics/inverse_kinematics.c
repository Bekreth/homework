#include <stdlib.h>
#include <math.h>

#include "inverse_kinematics.h"

const float MINIMUM_LENGTH = ARM_LENGTH_1 - ARM_LENGTH_2;
const float MAXIMUM_LENGTH = ARM_LENGTH_1 + ARM_LENGTH_2;

bool one_arm_ik(float, float*, float*);
bool two_arm_ik(float, float, float*, float*, Handedness);
bool valid_length(float);
void law_of_cosines(
	float length_a, float length_b, float length_c, 
	float* angle_a, float* angle_b, float* angle_c
);

bool calculate_scara_ik(
	float x_pos, float y_pos,
	float* angle_1, float* angle_2, 
	Handedness handedness
) {
	float straight_length = sqrt(pow(x_pos, 2) + pow(y_pos, 2));
	if (!valid_length(straight_length)) {
		return false;
	}

	float offset_angle = atan2(y_pos, x_pos);
	if (straight_length == MAXIMUM_LENGTH) {
		return one_arm_ik(offset_angle, angle_1, angle_2);
	} else {
		return two_arm_ik(straight_length, offset_angle, angle_1, angle_2, handedness);
	}
}

// Verfiy that the specified length is achievable
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
	float major_angle = 0.0;
	float minor_angle = 0.0;
	float third_angle = 0.0;
	law_of_cosines(ARM_LENGTH_1, ARM_LENGTH_2, straight_length, &third_angle, &major_angle, &minor_angle);

	float possible_angle_1;
	float possible_angle_2;
	if (handedness == Right) {
		possible_angle_1 = (offset_angle - major_angle) * (180.0 / M_PI);
		possible_angle_2 = ((M_PI - minor_angle)) * (180 / M_PI );
	} else if (handedness == Left) {
		possible_angle_1 = (offset_angle + major_angle) * (180.0 / M_PI );
		possible_angle_2 = (-1.0 * (M_PI - minor_angle)) * (180.0 / M_PI);
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

void law_of_cosines(
	float length_a, float length_b, float length_c,
	float* angle_a, float* angle_b, float* angle_c
) {
	float a_numerator = pow(length_b, 2) + pow(length_c, 2) - pow(length_a, 2);
	float a_denomenator = 2 * length_b * length_c;
	*angle_a = acos(a_numerator / a_denomenator);

	float b_numerator = pow(length_c, 2) + pow(length_a, 2) - pow(length_b, 2);
	float b_denomenator = 2 * length_c * length_a;
	*angle_b = acos(b_numerator / b_denomenator);

	float c_numerator = pow(length_a, 2) + pow(length_b, 2) - pow(length_c, 2);
	float c_denomenator = 2 * length_a * length_b;
	*angle_c = acos(c_numerator / c_denomenator);
}


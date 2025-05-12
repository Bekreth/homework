#include <stdlib.h>
#include "limits.h"

bool valid_angles(float angle1, float angle2) {
	angle1 *= angle1 < 0 ? -1 : 1;
	angle2 *= angle2 < 0 ? -1 : 1;
	if (angle1 > MAX_ANGLE_1) {
		return false;
	}
	if (angle2 > MAX_ANGLE_2) {
		return false;
	}
	return true;
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

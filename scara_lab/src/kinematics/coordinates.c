#include <float.h>

#include "coordinates.h"

float slope(Coordinate coordinate_0, Coordinate coordinate_1) {
	float rise = coordinate_1.y_pos - coordinate_0.y_pos;
	float run = coordinate_1.x_pos - coordinate_0.x_pos;

	if (rise == 0) {
		return 0;
	}
	if (run == 0) {
		return FLT_MAX;
	}

	return rise / run;
}

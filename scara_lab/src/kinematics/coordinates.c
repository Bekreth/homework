#include <float.h>
#include <stdlib.h>

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

void free_coordinates(Coordinates coordinates) {
	free(coordinates.coordinates);
}

Quadrant which_quadrant(Coordinate coordinate) {
	if (coordinate.x_pos >= 0 && coordinate.y_pos >= 0) {
		return Q1;
	} else if (coordinate.x_pos < 0 && coordinate.y_pos >= 0) {
		return Q2;
	} else if (coordinate.x_pos < 0 && coordinate.y_pos < 0) {
		return Q3;
	} else {
		return Q4;
	}
}

Coordinate x_intercept(Coordinate coordinate_0, Coordinate coordinate_1) {
	float point_slope = slope(coordinate_0, coordinate_1);
	float delta_x = coordinate_0.y_pos * 1/(point_slope);
	Coordinate output = {
		.x_pos = coordinate_0.x_pos - delta_x,
		.y_pos = 0
	};
	return output;
}

Coordinate y_intercept(Coordinate coordinate_0, Coordinate coordinate_1) {
	float point_slope = slope(coordinate_0, coordinate_1);
	float delta_y = coordinate_0.x_pos * point_slope;
	Coordinate output = {
		.x_pos = 0,
		.y_pos = coordinate_0.y_pos - delta_y
	};
	return output;
}

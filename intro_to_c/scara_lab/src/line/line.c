#include <float.h>

#include "line.h"

Line new_line(
	Coordinate starting_coordinate,
	Coordinate ending_coordinate,
	unsigned int subdivisions
) {
	float line_slope = slope(starting_coordinate, ending_coordinate);

	Color color = {
		.red = line_slope < 0 ? 255 : 0,
		.blue = line_slope > 0 && line_slope < FLT_MAX ? 255 : 0,
		.green = line_slope == 0 ? 255 : 0,
	};

	Line line = {
		.starting_coordinate = starting_coordinate,
		.ending_coorinate = ending_coordinate,
		.subdivisions = subdivisions,
		.color = color
	};
	return line;
}

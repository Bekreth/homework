#include <stdio.h>
#include <math.h>

#include "coordinate.h"

// TODO: All four quadrents will need to be sorted out individually 0_o
PolarCoordinates convert_to_polar(RectangularCoordinates input) {
	PolarCoordinates output;
	output.radius = sqrt(pow(input.x, 2) + pow(input.y, 2));
	if (input.x == 0) {
		if (input.y > 0) {
			output.angle = 90.0;
		} else if (input.y < 0) {
			output.angle = -90.0;
		} else {
			output.angle = 0.0;
		}
	} else {
		double degrees = atan(input.y / input.x) * (180.0 / M_PI);
		output.angle = fmod(degrees, 180.0);
	}
	return output;
}

RectangularCoordinates convert_to_rectangular(PolarCoordinates input) {
	RectangularCoordinates output;
	return output;
}

void print_coodrinates(
		RectangularCoordinates rectangular_coordinates, 
		PolarCoordinates polar_coordinates
	) {
	char y_sign = rectangular_coordinates.y >= 0 ? '+' : '-';
	char theta_sign = polar_coordinates.angle >= 0 ? '+' : '-';
	printf(
		"%d %c %di = %.2f /_ %c%.2f\n",
		rectangular_coordinates.x,
		y_sign,
		rectangular_coordinates.y < 0 ? -1 * rectangular_coordinates.y : rectangular_coordinates.y,

		polar_coordinates.radius,
		theta_sign,
		polar_coordinates.angle < 0 ? -1 * polar_coordinates.angle : polar_coordinates.angle
	);
}

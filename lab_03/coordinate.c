#include <stdio.h>
#include <math.h>

#include "coordinate.h"

// TODO: All four quadrents will need to be sorted out individually 0_o
PolarCoordinates convert_to_polar(RectangularCoordinates input) {
	PolarCoordinates output;
	output.radius = sqrt(pow(input.x, 2) + pow(input.y, 2));
	Quadrant quadrant = determine_quadrant(input);

	if (input.x == 0) {
		if (input.y > 0) {
			output.angle = 90.0;
		} else if (input.y < 0) {
			output.angle = -90.0;
		} else {
			output.angle = 0.0;
		}
	} else {
		double positive_x = input.x > 0 ? input.x : -1 * input.x;
		double positive_y = input.y > 0 ? input.y : -1 * input.y;
		output.angle = atan(positive_y / positive_x) * (180.0 / M_PI);
		switch (quadrant) {
			case Q1:
				break;
			case Q2:
				output.angle += 90.0;
				if (input.y == 0) {
					output.angle += 90.0;
				}
				break;
			case Q3:
				output.angle += 90.0;
				output.angle *= -1;
				break;
			case Q4:
				output.angle *= -1;
				break;
		}
	}
	return output;
}

Quadrant determine_quadrant(RectangularCoordinates input) {
	Quadrant output = Q1;
	if (input.x == 0) {
		if (input.y >= 0) {
			output = Q1;
		} else {
			output = Q3;
		}
	} else if (input.x > 0) {
		if (input.y >= 0) {
			output = Q1;
		} else {
			output = Q4;
		}
	} else {
		if (input.y >= 0) {
			output = Q2;
		} else {
			output = Q3;
		}
	}
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

#include <stdio.h>
#include <math.h>

#include "coordinate.h"

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
		double positive_x = input.x > 0.0 ? input.x : -1.0 * input.x;
		double positive_y = input.y > 0.0 ? input.y : -1.0 * input.y;
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

RectangularCoordinates convert_to_rectangular(PolarCoordinates input) {
	RectangularCoordinates output;
	output.x = input.radius * cos(input.angle / (180.0 / M_PI));
	output.y = input.radius * sin(input.angle / (180.0 / M_PI));
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

void print_polar_coodrinates(
	PolarCoordinates polar_coordinates
) {
	char theta_sign = polar_coordinates.angle >= 0 ? '+' : '-';
	printf(
		"%.2f /_ %c%.2f",
		polar_coordinates.radius,
		theta_sign,
		polar_coordinates.angle < 0 ? -1 * polar_coordinates.angle : polar_coordinates.angle
	);
}

void print_rectangular_coodrinates(
	RectangularCoordinates rectangular_coordinates
) {
	char y_sign = rectangular_coordinates.y >= 0 ? '+' : '-';
	printf(
		"%.2f %c %.2f",
		rectangular_coordinates.x,
		y_sign,
		rectangular_coordinates.y < 0.0 ? -1.0 * rectangular_coordinates.y : rectangular_coordinates.y
	);
}

#ifndef LINE_H
#define LINE_H

#include "coordinates.h"

typedef struct Color {
	unsigned int red;
	unsigned int green;
	unsigned int blue;
} Color;


typedef struct Line {
	Coordinate starting_coordinate;
	Coordinate ending_coorinate;
	unsigned int subdivisions;
	Color color;
} Line;

Line new_line(Coordinate, Coordinate, unsigned int);

#endif

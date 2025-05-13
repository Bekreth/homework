#ifndef COORDINATES_H
#define COORDINATES_H

#include <stdbool.h>

typedef enum Quadrant {
	Q1,
	Q2,
	Q3,
	Q4
} Quadrant;

typedef struct Coordinate {
	float x_pos;
	float y_pos;
} Coordinate;

typedef struct Coordinates {
	int length;
	Coordinate* coordinates;
} Coordinates;


float slope(Coordinate, Coordinate);
void free_coordinates(Coordinates);
Quadrant which_quadrant(Coordinate);
Coordinate new_coordinate(float, float);
Coordinate x_intercept(Coordinate, Coordinate);
Coordinate y_intercept(Coordinate, Coordinate);
bool coordinates_equal(Coordinate, Coordinate);

#endif


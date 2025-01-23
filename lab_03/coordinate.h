#ifndef COORDINATE_H
#define COORDINATE_H

typedef struct RectangularCoordinates {
	int x;
	int y;
} RectangularCoordinates;

typedef struct PolarCoordinates {
	double radius;
	double angle;
} PolarCoordinates;

typedef enum Quadrant {
	Q1 = 0,
	Q2 = 1,
	Q3 = 2,
	Q4 = 3,
} Quadrant;

PolarCoordinates convert_to_polar(RectangularCoordinates);
Quadrant determine_quadrant(RectangularCoordinates input);
void print_coodrinates(RectangularCoordinates, PolarCoordinates);


#endif

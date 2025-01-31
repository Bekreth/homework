#ifndef COORDINATE_H
#define COORDINATE_H

typedef struct RectangularCoordinates {
	double x;
	double y;
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
RectangularCoordinates convert_to_rectangular(PolarCoordinates);
Quadrant determine_quadrant(RectangularCoordinates input);
void print_rectangular_coodrinates(RectangularCoordinates);
void print_polar_coodrinates(PolarCoordinates);


#endif

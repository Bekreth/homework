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

PolarCoordinates convert_to_polar(RectangularCoordinates);
RectangularCoordinates convert_to_rectangular(PolarCoordinates);
void print_coodrinates(RectangularCoordinates, PolarCoordinates);


#endif

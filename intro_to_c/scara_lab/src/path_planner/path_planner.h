#ifndef PATH_PLANNER_H
#define PATH_PLANNER_H

#include <stdbool.h>
#include "kinematics.h"

typedef enum Boundary {
	Q12,
	Q23,
	Q34,
	Q41
} Boundary;

typedef struct PossiblePathing {
	Coordinate starting_coordinate;
	Coordinate ending_coordinate;
	bool is_right_handed;
	bool is_left_handed;
} PossiblePathing;

typedef struct PossiblePathings {
	int length;
	PossiblePathing* pathings;
} PossiblePathings;

// Divide path takes two starting coordinates and breakes out a linear
// path between them.
Coordinates divide_path(Coordinate, Coordinate, int);

// Takes a list of coordinates and determines whether left or right handed
// motion can move from one part to another
PossiblePathings create_possible_paths(Coordinates);

#endif

#ifndef PATH_PLANNER_H
#define PATH_PLANNER_H

#include <stdbool.h>
#include "kinematics.h"

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
PossiblePathings create_possible_paths(Coordinates);

#endif

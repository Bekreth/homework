#ifndef PATH_DIVIDER_H
#define PATH_DIVIDER_H

#include "coordinates.h"

// Divide path takes two starting coordinates and breakes out a linear
// path between them. 
void divide_path(Coordinate, Coordinate, int, Coordinate**);

#endif

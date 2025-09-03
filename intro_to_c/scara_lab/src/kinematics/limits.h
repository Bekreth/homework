#ifndef LIMITS_H
#define LIMITS_H

#define MAX_ANGLE_1 150.0
#define MAX_ANGLE_2 170.0

#define ARM_LENGTH_1 350.0
#define ARM_LENGTH_2 250.0

#define MINIMUM_LENGTH (ARM_LENGTH_1 - ARM_LENGTH_2)
#define MAXIMUM_LENGTH (ARM_LENGTH_1 + ARM_LENGTH_2)

#include <stdbool.h>

bool valid_angles(float, float);
bool valid_length(float);

#endif


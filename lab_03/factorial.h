#ifndef FACTORIAL_H
#define FACTORIAL_H

#include "error_code.h"

#define FACTORIAL_MAX 20

typedef struct PossibleValue {
	unsigned long value;
	ErrorCode error_code;
} PossibleValue;

PossibleValue calculate_factorial(int);
#endif

#include <stdlib.h>
#include <stdbool.h>

#include "validate_number.h"

bool valid_int_input(char* input) {
	int number = atoi(input);
	return number != 0 || (number == 0 && input[0] == '0');
}

bool valid_float_input(char* input) {
	float number = atof(input);
	return number != 0 || (number == 0 && input[0] == '0');
}


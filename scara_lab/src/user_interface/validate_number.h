#ifndef VALIDATE_NUMBER_H
#define VALIDATE_NUMBER_H

#include <stdbool.h>

// The following are only crude approximations of a string validation and
// should be trusted sparingly. 
bool valid_int_input(char*);
bool valid_float_input(char*);

#endif

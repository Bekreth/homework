#ifndef COORDINATES_TEST_H
#define COORDINATES_TEST_H

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>

#include "kinematics.h"
#include "coordinates.c"

void slope_test(void **state);
void x_intercept_test(void **state);
void y_intercept_test(void **state);

int run_coordinate_tests(); 

#endif

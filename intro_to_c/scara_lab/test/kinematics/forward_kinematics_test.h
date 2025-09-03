#ifndef FORWARD_KINEMATICS_TEST_H
#define FORWARD_KINEMATICS_TEST_H

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>

void fk_movement_in_range(void **state);
void fk_axis_one_out_of_range(void **state);
void fk_axis_two_out_of_range(void **state);

int run_fk_tests(); 

#endif

#ifndef INVERSE_KINEMATICS_TEST_H
#define INVERSE_KINEMATICS_TEST_H

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>

void ik_movement_length_bounds(void **state);
void ik_movement_max_reach(void **state);

int run_ik_tests(); 

#endif


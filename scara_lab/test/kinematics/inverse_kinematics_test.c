#include <math.h>

#include "inverse_kinematics_test.h"

#include "kinematics.h"

const struct CMUnitTest inverse_kinematics_tests[] = {
	cmocka_unit_test(ik_movement_length_bounds),
	cmocka_unit_test(ik_movement_max_reach),
	cmocka_unit_test(ik_movement_offangle_reach),
	cmocka_unit_test(ik_movement_q1),
	cmocka_unit_test(ik_movement_q2),
	cmocka_unit_test(ik_movement_q3),
	cmocka_unit_test(ik_movement_q4)
};

int run_ik_tests() {
	return cmocka_run_group_tests_name(
		"Inverse Kinematics Tests",
		inverse_kinematics_tests,
		NULL,
		NULL
	);
}

// Verify that errors are spit out when the length of the desired target is out of range
void ik_movement_length_bounds(void **state) {
	float actual_angle_1 = 0;
	float actual_angle_2 = 0;

	// Too Long
	bool in_range = calculate_scara_ik(500.0, 500.0, &actual_angle_1, &actual_angle_2, Right);
	assert_false(in_range);

	// Too short
	in_range = calculate_scara_ik(20.0, 20.0, &actual_angle_1, &actual_angle_2, Right);
	assert_false(in_range);
}

// Verify that when there is only 1 solution (at full extension) both left and right hand solutions are the same
void ik_movement_max_reach(void **state) {
	float actual_angle_1 = 0;
	float actual_angle_2 = 0;

	// X+ Max
	bool in_range = calculate_scara_ik(600.0, 0.0, &actual_angle_1, &actual_angle_2, Right);
	assert_true(in_range);
	assert_float_equal(actual_angle_1, 0.0, 0.001);
	assert_float_equal(actual_angle_2, 0.0, 0.001);

	in_range = calculate_scara_ik(600.0, 0.0, &actual_angle_1, &actual_angle_2, Left);
	assert_true(in_range);
	assert_float_equal(actual_angle_1, 0.0, 0.001);
	assert_float_equal(actual_angle_2, 0.0, 0.001);


	// Y+ Max
	in_range = calculate_scara_ik(0.0, 600.0, &actual_angle_1, &actual_angle_2, Right);
	assert_true(in_range);
	assert_float_equal(actual_angle_1, 1/2 * M_PI, 0.001);
	assert_float_equal(actual_angle_2, 0.0, 0.001);

	in_range = calculate_scara_ik(0.0, 600.0, &actual_angle_1, &actual_angle_2, Left);
	assert_true(in_range);
	assert_float_equal(actual_angle_1, 1/2 * M_PI, 0.001);
	assert_float_equal(actual_angle_2, 0.0, 0.001);


	// Y- Max
	in_range = calculate_scara_ik(0.0, -600.0, &actual_angle_1, &actual_angle_2, Right);
	assert_true(in_range);
	assert_float_equal(actual_angle_1, -1/2 * M_PI, 0.001);
	assert_float_equal(actual_angle_2, 0.0, 0.001);

	in_range = calculate_scara_ik(0.0, -600.0, &actual_angle_1, &actual_angle_2, Left);
	assert_true(in_range);
	assert_float_equal(actual_angle_1, -1/2 * M_PI, 0.001);
	assert_float_equal(actual_angle_2, 0.0, 0.001);

}

void ik_movement_offangle_reach(void **state) {
	float actual_angle_1 = 0;
	float actual_angle_2 = 0;

	// 90 degree in Q1
	bool in_range = calculate_scara_ik(350.0, 250.0, &actual_angle_1, &actual_angle_2, Right);
	assert_true(in_range);
	assert_float_equal(actual_angle_1, 0.0, 0.01);
	assert_float_equal(actual_angle_2, 90.0, 0.01);

	in_range = calculate_scara_ik(350.0, 250.0, &actual_angle_1, &actual_angle_2, Left);
	assert_true(in_range);
	assert_float_equal(actual_angle_1, 71.08, 0.01);
	assert_float_equal(actual_angle_2, -90.0, 0.01);

	// 90 degree in Q4
	in_range = calculate_scara_ik(350.0, -250.0, &actual_angle_1, &actual_angle_2, Right);
	assert_true(in_range);
	assert_float_equal(actual_angle_1, -71.08, 0.01);
	assert_float_equal(actual_angle_2, 90.0, 0.01);

	in_range = calculate_scara_ik(350.0, -250.0, &actual_angle_1, &actual_angle_2, Left);
	assert_true(in_range);
	assert_float_equal(actual_angle_1, 0.0, 0.01);
	assert_float_equal(actual_angle_2, -90.0, 0.01);

	// 90 degree in Q2
	in_range = calculate_scara_ik(-250.0, 350.0, &actual_angle_1, &actual_angle_2, Right);
	assert_true(in_range);
	assert_float_equal(actual_angle_1, 90.0, 0.01);
	assert_float_equal(actual_angle_2, 90.0, 0.01);

	in_range = calculate_scara_ik(-250.0, 350.0, &actual_angle_1, &actual_angle_2, Left);
	assert_false(in_range);
	assert_float_equal(actual_angle_1, 90.0, 0.01);
	assert_float_equal(actual_angle_2, 90.0, 0.01);

	// 90 degree in Q3
	in_range = calculate_scara_ik(-250.0, -350.0, &actual_angle_1, &actual_angle_2, Right);
	assert_false(in_range);
	assert_float_equal(actual_angle_1, 90.0, 0.01);
	assert_float_equal(actual_angle_2, 90.0, 0.01);

	in_range = calculate_scara_ik(-250.0, -350.0, &actual_angle_1, &actual_angle_2, Left);
	assert_true(in_range);
	assert_float_equal(actual_angle_1, -90.0, 0.01);
	assert_float_equal(actual_angle_2, -90.0, 0.01);

}

void ik_movement_q1(void **state) {
	float actual_angle_1 = 0;
	float actual_angle_2 = 0;

	bool in_range = calculate_scara_ik(350.0, 200.0, &actual_angle_1, &actual_angle_2, Right);
	assert_true(in_range);
	assert_float_equal(actual_angle_1, -8.21, 0.01);
	assert_float_equal(actual_angle_2, 97.39, 0.01);

	actual_angle_1 = 0;
	actual_angle_2 = 0;
	in_range = calculate_scara_ik(350.0, 200.0, &actual_angle_1, &actual_angle_2, Left);
	assert_true(in_range);
	assert_float_equal(actual_angle_1, 67.70, 0.01);
	assert_float_equal(actual_angle_2, -97.39, 0.01);

}

void ik_movement_q2(void **state) {
	float actual_angle_1 = 0;
	float actual_angle_2 = 0;

	bool in_range = calculate_scara_ik(-350.0, 200.0, &actual_angle_1, &actual_angle_2, Right);
	assert_true(in_range);
	assert_float_equal(actual_angle_1, 112.30, 0.01);
	assert_float_equal(actual_angle_2, 97.39, 0.01);

	actual_angle_1 = 0;
	actual_angle_2 = 0;
	in_range = calculate_scara_ik(-350.0, 200.0, &actual_angle_1, &actual_angle_2, Left);
	assert_false(in_range);
}

void ik_movement_q3(void **state) {
	float actual_angle_1 = 0;
	float actual_angle_2 = 0;

	bool in_range = calculate_scara_ik(-350.0, -200.0, &actual_angle_1, &actual_angle_2, Right);
	assert_false(in_range);

	actual_angle_1 = 0;
	actual_angle_2 = 0;
	in_range = calculate_scara_ik(-350.0, -200.0, &actual_angle_1, &actual_angle_2, Left);
	assert_true(in_range);
	assert_float_equal(actual_angle_1, -112.30, 0.01);
	assert_float_equal(actual_angle_2, -97.39, 0.01);

}

void ik_movement_q4(void **state) {
	float actual_angle_1 = 0;
	float actual_angle_2 = 0;

	bool in_range = calculate_scara_ik(350.0, -200.0, &actual_angle_1, &actual_angle_2, Right);
	assert_true(in_range);
	assert_float_equal(actual_angle_1, -67.60, 0.1);
	assert_float_equal(actual_angle_2, 97.39, 0.01);

	actual_angle_1 = 0;
	actual_angle_2 = 0;
	in_range = calculate_scara_ik(350.0, -200.0, &actual_angle_1, &actual_angle_2, Left);
	assert_true(in_range);
	assert_float_equal(actual_angle_1, 8.21, 0.01);
	assert_float_equal(actual_angle_2, -97.39, 0.01);
}

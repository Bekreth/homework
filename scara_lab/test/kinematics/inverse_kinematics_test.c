#include <math.h>

#include "inverse_kinematics_test.h"

#include "kinematics.h"

const struct CMUnitTest inverse_kinematics_tests[] = {
	cmocka_unit_test(ik_movement_length_bounds),
	cmocka_unit_test(ik_movement_max_reach),
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


	// Y- Max
	in_range = calculate_scara_ik(0.0, 600.0, &actual_angle_1, &actual_angle_2, Right);
	assert_true(in_range);
	assert_float_equal(actual_angle_1, 3/2 * M_PI, 0.001);
	assert_float_equal(actual_angle_2, 0.0, 0.001);

	in_range = calculate_scara_ik(600.0, 0.0, &actual_angle_1, &actual_angle_2, Left);
	assert_true(in_range);
	assert_float_equal(actual_angle_1, 3/2 * M_PI, 0.001);
	assert_float_equal(actual_angle_2, 0.0, 0.001);


	// Y+ Max
	in_range = calculate_scara_ik(0.0, 600.0, &actual_angle_1, &actual_angle_2, Right);
	assert_true(in_range);
	assert_float_equal(actual_angle_1, 1/2 * M_PI, 0.001);
	assert_float_equal(actual_angle_2, 0.0, 0.001);

	in_range = calculate_scara_ik(600.0, 0.0, &actual_angle_1, &actual_angle_2, Left);
	assert_true(in_range);
	assert_float_equal(actual_angle_1, 1/2 * M_PI, 0.001);
	assert_float_equal(actual_angle_2, 0.0, 0.001);

}

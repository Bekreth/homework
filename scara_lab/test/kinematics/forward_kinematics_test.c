#include "forward_kinematics_test.h"

#include "kinematics.h"

const struct CMUnitTest forward_kinematics_tests[] = {
	cmocka_unit_test(fk_movement_in_range),
	cmocka_unit_test(fk_axis_one_out_of_range),
	cmocka_unit_test(fk_axis_two_out_of_range)
};

int run_fk_tests() {
	return cmocka_run_group_tests_name(
		"Forward Kinematics Tests",
		forward_kinematics_tests,
		NULL,
		NULL
	);
}

void fk_movement_in_range(void **state) {
	float actual_x = 0;
	float actual_y = 0;

	move_scara_fk(90.0, -90.0, &actual_x, &actual_y);
	assert_float_equal(actual_x, 250, 0.001);
	assert_float_equal(actual_y, 350, 0.001);

	move_scara_fk(90.0, 90.0, &actual_x, &actual_y);
	assert_float_equal(actual_x, -250, 0.001);
	assert_float_equal(actual_y, 350, 0.001);

	move_scara_fk(45.0, 45.0, &actual_x, &actual_y);
	assert_float_equal(actual_x, 247.49, 0.01);
	assert_float_equal(actual_y, 497.49, 0.01);

	move_scara_fk(-130.0, 50.0, &actual_x, &actual_y);
	assert_float_equal(actual_x, -181.56, 0.01);
	assert_float_equal(actual_y, -514.32, 0.01);
}

void fk_axis_one_out_of_range(void **state) {
	float actual_x = 0;
	float actual_y = 0;

	// too big
	move_scara_fk(160, 0.0, &actual_x, &actual_y);
	assert_float_equal(actual_x, 0, 0.001);
	assert_float_equal(actual_y, 0, 0.001);

	// too small
	move_scara_fk(-160, 0.0, &actual_x, &actual_y);
	assert_float_equal(actual_x, 0, 0.001);
	assert_float_equal(actual_y, 0, 0.001);

	// Just right
	move_scara_fk(90.0, 0.0, &actual_x, &actual_y);
	assert_float_equal(actual_x, 0, 0.001);
	assert_float_equal(actual_y, 600, 0.001);
}

void fk_axis_two_out_of_range(void **state) {
	float actual_x = 0;
	float actual_y = 0;

	// too big
	move_scara_fk(175, 0.0, &actual_x, &actual_y);
	assert_float_equal(actual_x, 0, 0.001);
	assert_float_equal(actual_y, 0, 0.001);

	// too small
	move_scara_fk(-175, 0.0, &actual_x, &actual_y);
	assert_float_equal(actual_x, 0, 0.001);
	assert_float_equal(actual_y, 0, 0.001);

	// Just right
	move_scara_fk(0.0, 90.0, &actual_x, &actual_y);
	assert_float_equal(actual_x, 350.0, 0.001);
	assert_float_equal(actual_y, 250.0, 0.001);
}

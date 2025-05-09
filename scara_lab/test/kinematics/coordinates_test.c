#include <math.h>

#include "coordinates_test.h"

const struct CMUnitTest coordinate_kinematics_tests[] = {
	cmocka_unit_test(slope_test),
	cmocka_unit_test(x_intercept_test),
	cmocka_unit_test(y_intercept_test)
};

int run_coordinate_tests() {
	return cmocka_run_group_tests_name(
		"Coordinate Tests",
		coordinate_kinematics_tests,
		NULL,
		NULL
	);
}

void slope_test(void **state) {
	Coordinate starting_coordinate = {
		.x_pos = 2,
		.y_pos = 10
	};
	Coordinate ending_coordinate = {
		.x_pos = 3,
		.y_pos = 8
	};
	float slope_value = slope(starting_coordinate, ending_coordinate);
	assert_float_equal(slope_value, -2.0, 0.001);
}

void x_intercept_test(void **state) {
	Coordinate starting_coordinate = {
		.x_pos = 2,
		.y_pos = 10
	};
	Coordinate ending_coordinate = {
		.x_pos = 3,
		.y_pos = 8
	};
	Coordinate actual_value = x_intercept(starting_coordinate, ending_coordinate);

	Coordinate expected_value = {
		.x_pos = 7,
		.y_pos = 0,
	};

	assert_float_equal(actual_value.x_pos, expected_value.x_pos, 0.001);
	assert_float_equal(actual_value.y_pos, expected_value.y_pos, 0.001);
}

void y_intercept_test(void **state) {
	Coordinate starting_coordinate = {
		.x_pos = 2,
		.y_pos = 10
	};
	Coordinate ending_coordinate = {
		.x_pos = 3,
		.y_pos = 8
	};
	Coordinate actual_value = y_intercept(starting_coordinate, ending_coordinate);

	Coordinate expected_value = {
		.x_pos = 0,
		.y_pos = 14,
	};

	assert_float_equal(actual_value.x_pos, expected_value.x_pos, 0.001);
	assert_float_equal(actual_value.y_pos, expected_value.y_pos, 0.001);
}


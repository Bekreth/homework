#include <math.h>

#include "path_planner_test.h"

#include "path_planner.h"

const struct CMUnitTest path_divider_tests[] = {
	cmocka_unit_test(path_divider_test),
};

int run_path_tests() {
	return cmocka_run_group_tests_name(
		"Path Divider Tests",
		path_divider_tests,
		NULL,
		NULL
	);
}

void path_divider_test(void **state) {
	Coordinate starting_point = {
		.x_pos = 2.0,
		.y_pos = 2.0,
	};

	Coordinate ending_point = {
		.x_pos = 12.0,
		.y_pos = 22.0,
	};

	Coordinates actual_coordinates = divide_path(starting_point, ending_point, 9);
	
	Coordinate expected_coordinates[10] = {
		starting_point,
		{
			.x_pos = 3.0,
			.y_pos = 4.0,
		},
		{
			.x_pos = 4.0,
			.y_pos = 6.0,
		},
		{
			.x_pos = 5.0,
			.y_pos = 8.0,
		},
		{
			.x_pos = 6.0,
			.y_pos = 10.0,
		},
		{
			.x_pos = 7.0,
			.y_pos = 12.0,
		},
		{
			.x_pos = 8.0,
			.y_pos = 14.0,
		},
		{
			.x_pos = 9.0,
			.y_pos = 16.0,
		},
		{
			.x_pos = 10.0,
			.y_pos = 18.0,
		},
		{
			.x_pos = 11.0,
			.y_pos = 20.0,
		},
		ending_point
	};

	for (int i = 0; i < 10; i++) {
		assert_float_equal(actual_coordinates.coordinates[i].x_pos, expected_coordinates[i].x_pos, 0.01);
		assert_float_equal(actual_coordinates.coordinates[i].y_pos, expected_coordinates[i].y_pos, 0.01);
	}
}

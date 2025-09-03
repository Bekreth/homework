#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>

#include "common.h"

static void test_cursor_move(void **state);

const struct CMUnitTest common_tests[] = {
	cmocka_unit_test(test_cursor_move)
};

Menu new_test_menu() {
	Menu menu_under_test;
	menu_under_test.length = 10;
	char elements [10][3] = {
		"one",
		"two",
		"thr",
		"fou",
		"fiv",
		"six",
		"sev",
		"eig",
		"nin",
		"ten"
	};
	menu_under_test.elements = elements;
	menu_under_test.cursor_enabled = 0;
	menu_under_test.cursor_position = 0;
	menu_under_test.cursor_length = 1;
	menu_under_test.cursor_character = "*";
	return menu_under_test;
}

static void test_cursor_move(void **state) {
	Menu menu_under_test = new_test_menu();

	move_cursor(&menu_under_test, Down, 1);
	assert_int_equal(menu_under_test.cursor_position, 1);

	move_cursor(&menu_under_test, Up, 2);
	assert_int_equal(menu_under_test.cursor_position, 9);

	move_cursor(&menu_under_test, Down, 1);
	assert_int_equal(menu_under_test.cursor_position, 0);

	move_cursor(&menu_under_test, Down, 5);
	assert_int_equal(menu_under_test.cursor_position, 5);

}

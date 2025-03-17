#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>

#include "sorter.h"

static void test_sorter(void **state);

const struct CMUnitTest sorter_tests[] = {
	cmocka_unit_test(test_sorter)
};


static void test_sorter(void **state) {
	int test_x[10] = {
		23,
		-3,
		19,
		-16,
		18,
		-27,
		5,
		9,
		28,
		-10
	};
	int test_y[10] = {
		8,
		-5,
		18,
		12,
		2,
		6,
		-23,
		0,
		28,
		3
	};


	int expected_test_x[10] = {
		-27,
		5,
		-3,
		-10,
		-16,
		9,
		18,
		23,
		19,
		28
	};
	int expected_test_y[10] = {
		6,
		-23,
		-5,
		3,
		12,
		0,
		2,
		8,
		18,
		28
	};


	sort_array_sums(test_x, test_y, 10);
	for (int i = 0; i < 10; i++) {
		assert_int_equal(expected_test_x[i], test_x[i]);
		assert_int_equal(expected_test_y[i], test_y[i]);
	}
}

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>

#include "common.h"

static void test_bitWiseEx1(void **state);
static void test_bitWiseEx2(void **state);
static void test_bitWiseEx3(void **state);

const struct CMUnitTest bitwise_tests[] = {
	cmocka_unit_test(test_bitWiseEx1),
	cmocka_unit_test(test_bitWiseEx2),
	cmocka_unit_test(test_bitWiseEx3)
};

// Given the incremental way that writes are done to terminal, there's no convient way of mocking out
// the system call functions to check values during the test.  While it is posssible to do, the effort
// would be better spent rewriting the framework for better testing. As such, all the following tests
// only validate the final state of the bitWiseEx# functions instead of the intermediate steps.

static void test_bitWiseEx1(void **state) {
	bitWiseEx1();
	assert_int_equal(P3OUT, 0b01011100);
}

static void test_bitWiseEx2(void **state) {
	bitWiseEx2();
	assert_int_equal(P3OUT, 0b01011010);
}

static void test_bitWiseEx3(void **state) {
	uint8_t test_array[5] = {
		0xAA,
		0xBB,
		0xCC,
		0xDD,
		0xFF
	};
	bitWiseEx3(test_array, 5);
	assert_int_equal(P3OUT, 0b00000001);
}

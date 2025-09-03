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

static void test_bitWiseEx1(void **state) {
	bitWiseEx1();
	assert_int_equal(P3OUT, 1);
}

static void test_bitWiseEx2(void **state) {
	bitWiseEx2();
	assert_int_equal(P3OUT, 1);
}

static void test_bitWiseEx3(void **state) {
	bitWiseEx3();
	assert_int_equal(P3OUT, 1);
}

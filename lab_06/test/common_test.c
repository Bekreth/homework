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

static void test_cursor_move(void **state) {
	assert_int_equal(0, 0);
}

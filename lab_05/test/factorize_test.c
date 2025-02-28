#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>

#include <stdbool.h>

#include "test_includes.h"


static void test_factorization(void **state);

const struct CMUnitTest factorize_tests[] = {
	cmocka_unit_test(test_factorization)
};

static void test_factorization(void **state) {
	Cache test_cache = new_cache();

	unsigned long expected_output_6[2] = {2,3};
	assert_factors(&test_cache, expected_output_6, 6);

	unsigned long expected_output_9[2] = {3,3};
	assert_factors(&test_cache, expected_output_9, 9);

	unsigned long expected_output_12[3] = {2,2,3};
	assert_factors(&test_cache, expected_output_12, 12);

	unsigned long expected_output_81[4] = {3,3,3,3};
	assert_factors(&test_cache, expected_output_81, 81);

	unsigned long expected_output_120[5] = {2,2,2,3,5};
	assert_factors(&test_cache, expected_output_120, 120);
}

void assert_factors(Cache* test_cache, unsigned long* expected, unsigned long test_digit) {
	PrimeFactors prime_factors = factorize(test_cache, test_digit);
	for (int i = 0; i < prime_factors.length; i++) {
		assert_int_equal(expected[i], prime_factors.factors[i]);
	}
}

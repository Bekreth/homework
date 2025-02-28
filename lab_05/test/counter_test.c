#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>

#include <stdio.h>
#include <stdbool.h>

#include "test_includes.h"

static void test_index_of_first_following_prime(void **state);
static void test_index_of_previous_preceding_prime(void **state);
static void test_count_primes(void **state);

const struct CMUnitTest counter_tests[] = {
	cmocka_unit_test(test_index_of_first_following_prime),
	cmocka_unit_test(test_index_of_previous_preceding_prime),
	cmocka_unit_test(test_count_primes)
};

static void test_index_of_first_following_prime(void **state) {
	Cache test_cache = new_cache();

	// Prime cache with a few primes
	// [2,3,5,7,11,13,19]
	is_prime(&test_cache, 19);

	int actual_index_1 = index_of_first_following_prime(test_cache.prime_cache, 10);
	assert_int_equal(actual_index_1, 4);

	int actual_index_2 = index_of_first_following_prime(test_cache.prime_cache, 11);
	assert_int_equal(actual_index_2, 4);

	int actual_index_3 = index_of_first_following_prime(test_cache.prime_cache, 12);
	assert_int_equal(actual_index_3, 5);
}

static void test_index_of_previous_preceding_prime(void **state) {
	Cache test_cache = new_cache();

	// Prime cache with a few primes
	// [2,3,5,7,11,13,19]
	is_prime(&test_cache, 19);

	int actual_index_1 = index_of_previous_preceding_prime(test_cache.prime_cache, 12);
	assert_int_equal(actual_index_1, 4);

	int actual_index_2 = index_of_previous_preceding_prime(test_cache.prime_cache, 11);
	assert_int_equal(actual_index_2, 4);

	int actual_index_3 = index_of_previous_preceding_prime(test_cache.prime_cache, 9);
	assert_int_equal(actual_index_3, 3);
}

static void test_count_primes(void **state) {
	Cache test_cache = new_cache();

	// [2,3,5,7,11,13,17,19]
	PrimeCount actual_output = count_primes(&test_cache, 10, 20);
	assert_int_equal(actual_output.primes[0], 11);
	assert_int_equal(actual_output.primes[1], 13);
	assert_int_equal(actual_output.primes[2], 17);
	assert_int_equal(actual_output.primes[3], 19);
}

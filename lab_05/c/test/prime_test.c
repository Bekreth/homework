#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>

#include <stdbool.h>

#include "test_includes.h"

static void test_divisible_by_known_primes(void **state);
static void test_number_is_known_composite(void **state);
static void test_is_prime(void **state);

const struct CMUnitTest prime_tests[] = {
	test_divisible_by_known_primes,
	test_number_is_known_composite
//	test_is_prime
};

static void test_divisible_by_known_primes(void **state) {
	Cache test_cache = new_cache();
	PrimeCache* test_prime_cache = test_cache.prime_cache;

	// Cache with primes but number isn't divisible by known primes
	assert_false(divisible_by_known_primes(test_prime_cache, 15));

	// Cache with primes and number is divisible by known primes
	append_prime_cache(test_prime_cache, 5);
	assert_true(divisible_by_known_primes(test_prime_cache, 15));

}

static void test_number_is_known_composite(void **state) {
	Cache test_cache = new_cache();
	CompositeCache* test_composite_cache = test_cache.composite_cache;

	// number larger than largest known composite
	assert_false(number_is_known_composite(test_composite_cache, 100));

	// known composite
	assert_true(number_is_known_composite(test_composite_cache, 4));

	// Unknown composite within upper bounds
	append_composite_cache(test_composite_cache, 10);
	assert_false(number_is_known_composite(test_composite_cache, 6));
}

static void test_is_prime(void **state) {
	Cache test_cache = new_cache();
}

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>

#include "test_includes.h"

static void test_append_prime_cache(void **state);
static void test_append_composite_cache(void **state);
const struct CMUnitTest cache_tests[] = {
		cmocka_unit_test(test_append_prime_cache),
		cmocka_unit_test(test_append_composite_cache)
};

static void test_append_prime_cache(void **state) {
	Cache cache = new_cache();
	PrimeCache* cache_under_test = cache.prime_cache;

	assert_int_equal(cache_under_test->capacity, 10);
	assert_int_equal(cache_under_test->length, 1);

	for (int i = 0; i <= 8; i++) {
		append_prime_cache(cache_under_test, 10+i);
	}

	assert_int_equal(cache_under_test->capacity, 10);
	assert_int_equal(cache_under_test->length, 10);

	append_prime_cache(cache_under_test, 19);

	assert_int_equal(cache_under_test->capacity, 20);
	assert_int_equal(cache_under_test->length, 11);

	assert_int_equal(cache_under_test->largest_known_prime, 19);
}


static void test_append_composite_cache(void **state) {
	Cache cache = new_cache();
	CompositeCache* cache_under_test = cache.composite_cache;

	assert_int_equal(cache_under_test->capacity, 10);
	assert_int_equal(cache_under_test->length, 1);

	for (int i = 0; i <= 8; i++) {
		append_composite_cache(cache_under_test, 10+i);
	}

	assert_int_equal(cache_under_test->capacity, 10);
	assert_int_equal(cache_under_test->length, 10);

	append_composite_cache(cache_under_test, 19);

	assert_int_equal(cache_under_test->capacity, 20);
	assert_int_equal(cache_under_test->length, 11);

	assert_int_equal(cache_under_test->largest_known_composite, 19);
}


#include <stdio.h>

#include "factorize.c"
#include "prime.c"

int main() {
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(null_test_success),
		cmocka_unit_test(test_append_prime_cache),
		cmocka_unit_test(test_append_composite_cache),
	};

	return cmocka_run_group_tests(tests, NULL, NULL);
}

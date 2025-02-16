#include <stdio.h>

#include "factorize.c"

int main() {
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(null_test_success),
	};

	return cmocka_run_group_tests(tests, NULL, NULL);
}

#include <stdio.h>

#include "cache_test.c"
#include "prime_test.c"
#include "counter_test.c"
#include "factorize_test.c"

int main() {
	int cache_test_result = cmocka_run_group_tests_name(
		"Cache Tests", 
		cache_tests, 
		NULL, 
		NULL
	);
	int prime_test_result = cmocka_run_group_tests_name(
		"Prime Tests",
		prime_tests,
		NULL,
		NULL
	);
	int counter_test_result = cmocka_run_group_tests_name(
		"Counter Tests", 
		counter_tests, 
		NULL, 
		NULL
	);
	int factorize_test_result = cmocka_run_group_tests_name(
		"Factorize Tests", 
		factorize_tests, 
		NULL, 
		NULL
	);

	return cache_test_result && 
		prime_test_result && 
		counter_test_result && 
		factorize_test_result;
}

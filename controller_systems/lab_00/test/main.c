#include "common_test.c"

int main() {
	int bitwise_test_results = cmocka_run_group_tests_name(
		"Bit Wise Tests", 
		bitwise_tests, 
		NULL, 
		NULL
	);

	return bitwise_test_results;
}

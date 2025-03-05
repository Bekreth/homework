#include "common_test.c"

int main() {
	int cursor_test_results = cmocka_run_group_tests_name(
		"Cursor Tests", 
		common_tests, 
		NULL, 
		NULL
	);
}

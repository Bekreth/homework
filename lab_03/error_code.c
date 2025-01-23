#include "error_code.h"


void handle_error_codes(ErrorCode error_code, int user_input) {
	switch (error_code) {
		case NegativeInput:
			printf("Please enter only positive numbers.\n");
			break;
		case FactorialOverflow:
			printf("Arithmetic overflow: %d exceeds max.\n", user_input);
			break;
		default:
			printf("CRITIAL ERROR: %d has no case statement\n", error_code);
			break;
	}
	return;
}

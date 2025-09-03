#include "error_code.h"
#include "factorial.h"

PossibleValue calculate_factorial(int iterations) {
	PossibleValue output;
	output.value = 0;
	output.error_code = None;
	if (iterations <= 0) {
		output.error_code = NegativeInput;
		return output;
	}
	if (iterations > FACTORIAL_MAX) {
		output.error_code = FactorialOverflow;
		return output;
	}
	output.value += 1;
	for (int i = iterations; i > 1; i--) {
		output.value *= i;
	}
	return output;
}


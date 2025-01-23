#include <stdio.h>

#include "error_code.h"
#include "factorial.h"

typedef enum PolarPicker {
	Radius = 0,
	Angle = 1
} PolarPicker ;

unsigned long fibonacci(int iterations);

// Returns _EITHER_ Radius or Angle
float rectToPolar(int, int, PolarPicker);

int main() {
	int factorial_input;
	while (1) {
		printf("Enter a number: ");
		scanf("%d", &factorial_input);
		if (factorial_input == -99) {
			break;
		}
		PossibleValue factorial = calculate_factorial(factorial_input);
		if (factorial.error_code != None) {
			handle_error_codes(factorial.error_code, factorial_input);
			continue;
		}
		printf("%d! = %ld\n", factorial_input, factorial.value);
	}

	printf("%ld\n", fibonacci(10));
}

float rectToPolar(int, int, PolarPicker) {
}

unsigned long fibonacci(int iterations) {
	int previous = 0;
	int output = 0;
	int next_step = 1;
	for (int i = 0; i <= iterations; i++) {
		previous = output;
		output += next_step;
		next_step = previous;
	}
	return output;
}

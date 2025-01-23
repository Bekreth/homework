#include <stdio.h>

#include "error_code.h"
#include "factorial.h"
#include "coordinate.h"


unsigned long fibonacci(int iterations);

int main() {
	int factorial_input;
	while (0) {
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

	RectangularCoordinates input_coordinates;
	input_coordinates.x = 0;
	input_coordinates.y = 0;
	scanf("%d,%d", &input_coordinates.x, &input_coordinates.y);
	printf("data %d  - %d\n", input_coordinates.x, input_coordinates.y);
	PolarCoordinates output_coordinates = convert_to_polar(input_coordinates);
	print_coodrinates(input_coordinates, output_coordinates);
	//printf("%ld\n", fibonacci(10));
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

#include <stdio.h>

#include "error_code.h"
#include "factorial.h"
#include "fibonacci.h"
#include "coordinate.h"

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
	while (0) {
		printf("Please provide coordinates x,y\n");
		scanf("%d,%d", &input_coordinates.x, &input_coordinates.y);
		PolarCoordinates output_coordinates = convert_to_polar(input_coordinates);
		if (output_coordinates.radius == 0) {
			break;
		}
		print_coodrinates(input_coordinates, output_coordinates);
	}
	int fibonacci_target;
	printf("Please provide fibonacci number: ");
	scanf("%d", &fibonacci_target);
	fibonacci(fibonacci_target);
}

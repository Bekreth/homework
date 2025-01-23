#include <stdio.h>

#include "main.h"
#include "error_code.h"
#include "factorial.h"
#include "fibonacci.h"
#include "coordinate.h"

int main() {
	handle_factorial();
	handle_rectangular_polar_conversion();
	handle_fibonacci();
}

void handle_factorial() {
	printf("** Launching factorial solver. Exit by entering '-99'\n");
	int factorial_input;
	while (1) {
		printf("Enter a number: ");
		scanf("%d", &factorial_input);
		if (factorial_input == -99) {
			printf("-- Exiting factorial solver\n");
			break;
		}
		PossibleValue factorial = calculate_factorial(factorial_input);
		if (factorial.error_code != None) {
			handle_error_codes(factorial.error_code, factorial_input);
			continue;
		}
		printf("%d! = %ld\n", factorial_input, factorial.value);
	}
}

void handle_rectangular_polar_conversion() {
	printf("** Launching rectangular to polar coordinate converter. Exit by entering '0,0'\n");
	RectangularCoordinates input_coordinates;
	input_coordinates.x = 0;
	input_coordinates.y = 0;
	while (1) {
		printf("Please provide coordinates x,y\n");
		scanf("%d,%d", &input_coordinates.x, &input_coordinates.y);
		if (input_coordinates.x == 0 && input_coordinates.y == 0) {
			printf("-- Exiting rectangular to polar converter\n");
			break;
		}
		PolarCoordinates output_coordinates = convert_to_polar(input_coordinates);
		print_coodrinates(input_coordinates, output_coordinates);
	}
}

void handle_fibonacci() {
	printf("** Launching fibonacci solver. Exit by entering '0'\n");
	while(1) {
		int fibonacci_target;
		if (fibonacci_target <= 0) {
			printf("-- Exiting fibonacci solver\n");
			break;
		}
		printf("Please provide fibonacci number: ");
		scanf("%d", &fibonacci_target);
		fibonacci(fibonacci_target);
	}
}

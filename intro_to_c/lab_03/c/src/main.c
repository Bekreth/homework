/******************************************************************************
 * * ROBT 1270 C Programing
 * * LAB #3
 * *
 * * Purpose: Demonstrate I understand C
 * *
 * * Author: Christopher Hughes
 * * ROBT1270, Set B
 * *
 * * Declaration:
 * * I wrore this program
 * *
 * * Date Created: 25.01.22
 * *
 * ******************************************************************************/

#include <stdio.h>

#include "main.h"
#include "error_code.h"
#include "factorial.h"
#include "fibonacci.h"
#include "coordinate.h"

int main() {
	Operation user_input;
	while(1) {
		print_menu();
		scanf("%d", &user_input);
		switch (user_input) {
			case FACTORIAL:
				handle_factorial();
				break;
			case FIBONACCI:
				handle_fibonacci();
				break;
			case RECT_TO_POLAR:
				handle_rectangular_to_polar_conversion();
				break;
			case POLAR_TO_RECT:
				handle_polar_to_rectangular_conversion();
				break;
			case EXIT:
				printf("\nThank you for your time!\n\n");
				return 0;
				break;
			default:
				printf("Invalid input");
				break;
		}
	}
}

void print_menu() {
	printf("Welcom to lab 3.  Select your desired operation!\n");
	printf("1: Factorial\n");
	printf("2: Fibonacci\n");
	printf("3: Rectangular to Polar\n");
	printf("4: Polar to Rectangular\n");
	printf("5: Exist Lab03\n\n");
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

void handle_rectangular_to_polar_conversion() {
	printf("** Launching rectangular to polar coordinate converter. Exit by entering '0,0'\n");
	RectangularCoordinates input_coordinates;
	input_coordinates.x = 0.0;
	input_coordinates.y = 0.0;
	while (1) {
		printf("Please provide coordinates x,y\n");
		scanf("%lf,%lf", &input_coordinates.x, &input_coordinates.y);
		if (input_coordinates.x == 0.0 && input_coordinates.y == 0.0) {
			printf("-- Exiting rectangular to polar converter\n");
			break;
		}
		PolarCoordinates output_coordinates = convert_to_polar(input_coordinates);
		print_rectangular_coodrinates(input_coordinates),
		printf(" = ");
		print_polar_coodrinates(output_coordinates),
		printf("\n");
	}
}

void handle_polar_to_rectangular_conversion() {
	printf("** Launching polar to rectangular coordinate converter. Exit by entering '0,0'\n");
	PolarCoordinates input_coordinates;
	input_coordinates.radius = 0;
	input_coordinates.angle = 0;
	while (1) {
		printf("Please provide coordinates r,O\n");
		scanf("%lf,%lf", &input_coordinates.radius, &input_coordinates.angle);
		if (input_coordinates.radius == 0 && input_coordinates.angle == 0) {
			printf("-- Exiting polar to rectangular converter\n");
			break;
		}
		RectangularCoordinates output_coordinates = convert_to_rectangular(input_coordinates);

		print_polar_coodrinates(input_coordinates),
		printf(" = ");
		print_rectangular_coodrinates(output_coordinates),
		printf("\n");
	}
}

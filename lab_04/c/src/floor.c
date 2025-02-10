#include <stdio.h>
#include <math.h>

#include "floor.h"

const char* FLOOR_FORMATTING_TEMPLATE = "|%-10.0lf|%-10.1lf|%-10.2lf|%-10.3lf|%-10lf|";
const char* ANSI_ESCAPE = "\x1B";
const char* ANSI_CARRIAGE_RETURN = "\x0D";

void introduce_floor();
double round_to_integer(double);
double round_to_tenths(double);
double round_to_hundredths(double);
double round_to_thousandths(double);
double round_to_decimal(double, int);

void run_floor() {
	introduce_floor();
	while (1) {
		double user_input = 0.0;
		printf("Enter value please: ");
		scanf("%lf", &user_input);
		if (user_input == 0.0) {
			break;
		}

		char rounded_values[256];
		sprintf(
			&rounded_values,
			FLOOR_FORMATTING_TEMPLATE,
			round_to_integer(user_input),
			round_to_tenths(user_input),
			round_to_hundredths(user_input),
			round_to_thousandths(user_input),
			user_input
		);

		printf(
			"\033[#F%s\n", 
			rounded_values
		);
	}

	printf("Thank you for rounding\n");
}

void introduce_floor() {
	printf("Welcome to Rounding! Please enter a decial value to see it rounded. Enter 0 to exit\n\n");
	printf("--------------------------------------------------------\n");
	printf("|1         |0.1       |0.01      |0.001     |User value|\n");
}

double round_to_integer(double user_input) {
	return round_to_decimal(user_input, 0);
}

double round_to_tenths(double user_input) {
	return round_to_decimal(user_input, 1);
}

double round_to_hundredths(double user_input) {
	return round_to_decimal(user_input, 2);
}

double round_to_thousandths(double user_input) {
	return round_to_decimal(user_input, 3);
}


double round_to_decimal(double user_input, int decimal_position) {
	int offset_factor = (int) pow(10, decimal_position);
	double output = floor(user_input * offset_factor + 0.5)/offset_factor;
	return output;
}


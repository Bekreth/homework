#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "floor.h"
#include "screen_writer.h"

const char* FLOOR_FORMATTING_TEMPLATE = "|%-10.0lf|%-10.1lf|%-10.2lf|%-10.3lf|%-10lf|";

double round_to_integer(double);
double round_to_tenths(double);
double round_to_hundredths(double);
double round_to_thousandths(double);
double round_to_decimal(double, int);

ScreenView build_floor_view();

void run_floor() {
	ScreenView screen_view = build_floor_view();
	while (1) {
		draw_screen_view(screen_view);
		double user_input = 0.0;
		scanf("%lf", &user_input);
		if (user_input == 0.0) {
			break;
		}

		char* rounded_values = malloc(sizeof(char) * 55);
		sprintf(
			rounded_values,
			FLOOR_FORMATTING_TEMPLATE,
			round_to_integer(user_input),
			round_to_tenths(user_input),
			round_to_hundredths(user_input),
			round_to_thousandths(user_input),
			user_input
		);
		screen_view.content_length += 1;
		screen_view.content = realloc(
			screen_view.content, 
			sizeof(ScreenLine) * screen_view.content_length
		);
		ScreenLine updated_line = {
			.line = rounded_values,
			.line_length = 256
		};
		screen_view.content[screen_view.content_length-1] = updated_line;
	}
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

ScreenView build_floor_view() {
	ScreenView output;
	ScreenLine header_line = {
		.line = "Welcome to Rounding! Please enter a decial value to see it rounded. Enter 0 to exit",
		.line_length = 80,
	};
	output.header = header_line;

	//TODO: The first two lines of this aren't "content".  Need to rework the screen writer header
	output.content_length = 2;
	output.content = malloc(sizeof(ScreenView) * output.content_length);

	ScreenLine line_0 = {
		.line = "--------------------------------------------------------",
		.line_length = 55,
	};
	output.content[0] = line_0;

	ScreenLine line_1 = {
		.line = "|1         |0.1       |0.01      |0.001     |User value|",
		.line_length = 55,
	};
	output.content[1] = line_1;

	ScreenLine user_input = {
		.line = " Enter value please: ",
		.line_length = 20,
	};
	output.user_input_prompt = user_input;

	return output;
}

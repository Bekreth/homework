#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "overtime.h"
#include "user_time.h"
#include "screen_writer.h"

UserTime get_user_input();

ScreenView build_overtime_view();

void run_overtime() {
	ScreenView screen_view = build_overtime_view();
	while(1) {
		draw_screen_view(screen_view);

		UserTime user_input_1 = get_user_input(1);
		if (is_zero(&user_input_1)) {
			break;
		}

		char* time_string_1 = to_string(&user_input_1);
		expand_content(&screen_view, time_string_1, 8);
		draw_screen_view(screen_view);

		UserTime user_input_2 = get_user_input(2);
		if (is_zero(&user_input_2)) {
			break;
		}

		char* time_string_2 = to_string(&user_input_2);
		expand_content(&screen_view, time_string_2, 8);

		char* response_string = malloc(sizeof(char) * 100);
		sprintf(
			response_string,
			"%d seconds have passed since %s and %s",
			calculate_delta_seconds(&user_input_1, &user_input_2),
			time_string_1,	
			time_string_2
		);
		expand_content(&screen_view, response_string, 100);
	}
}

ScreenView build_overtime_view() {
	ScreenView output;
	ScreenLine header_line = {
		.line = "Welcome to Overtime! Input a number an be told whether its even or odd. Enter 00:00:00 to exit",
		.line_length = 90,
	};
	output.header = header_line;

	output.content_length = 0;
	output.content = malloc(sizeof(ScreenLine) * 0);

	ScreenLine user_input = {
		.line = "Enter time (hh:mm:ss): ",
		.line_length = 22,
	};
	output.user_input_prompt = user_input;
	return output;
}

UserTime get_user_input(int counter) {
	UserTime user_input;
	scanf(
		"%d:%d:%d", 
		&user_input.hours,
		&user_input.minutes,
		&user_input.seconds
	);
	return user_input;
}

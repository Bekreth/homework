#include <stdio.h>

#include "even_or_odd.h"
#include "screen_writer.h"

const char* EVEN_ODD_FORMATTING_TEMPLATE = "|%-6s|%-10d|";

int is_even(int);

ScreenView build_even_or_odd_view();

void run_even_or_odd() {
	ScreenView screen_view = build_even_or_odd_view();
	while (1) {
		draw_screen_view(screen_view);
		int user_input = 0;
		scanf("%d", &user_input);
		if (user_input == 0) {
			break;
		}

		int even_odd_value_length = 55;
		char* even_odd_value = malloc(sizeof(char) * even_odd_value_length);
		sprintf(
			even_odd_value,
			EVEN_ODD_FORMATTING_TEMPLATE,
			is_odd(user_input) ? "Odd" : "Even",
			user_input
		);
		expand_content(&screen_view, even_odd_value, even_odd_value_length);
	}
	//free_screen_content(&screen_view);
}

int is_odd(int user_input) {
	return user_input % 2;
}

/**
The golfed solution is as follows. I will not run code through this.
o(int* i){*i%=2;}
 */

ScreenView build_even_or_odd_view() {
	ScreenView output;
	ScreenLine header_line = {
		.line = "Welcome to Getting Even! Input a number an be told whether its even or odd. Enter 0 to exit",
		.line_length = 80,
	};
	output.header = header_line;

	//TODO: The first two lines of this aren't "content".  Need to rework the screen writer header
	output.content_length = 2;
	output.content = malloc(sizeof(ScreenView) * output.content_length);

	ScreenLine line_0 = {
		.line = "-------------------",
		.line_length = 19,
	};
	output.content[0] = line_0;

	ScreenLine line_1 = {
		.line = "|Even? |User value|",
		.line_length = 19,
	};
	output.content[1] = line_1;

	ScreenLine user_input = {
		.line = " Enter value please: ",
		.line_length = 20,
	};
	output.user_input_prompt = user_input;

	return output;
}

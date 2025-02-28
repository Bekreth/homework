/**
 * Lab 05 - 
 */
#include <stdio.h>

#include "tui.h"

#include "main.h"
#include "prime.h"
#include "counter.h"
#include "factorize.h"
#include "cache/cache.h"

ScreenView build_menu_view();

int main() {
	Cache cache = new_cache();
	ScreenView screen_view = build_menu_view();
	MenuOption user_menu_selection = MainMenu;
	char user_input[20];

	while (1) {
		draw_screen_view(screen_view);
		fgets(user_input, 20, stdin);
		sscanf(user_input, "%i", &user_menu_selection);
		switch (user_menu_selection) {
			case MainMenu:
				break;
			case Prime:
				run_prime(&cache);
				break;
			case Counting:
				run_counter(&cache);
				break;
			case Factorizing:
				run_factorize(&cache);
				break;
			case Exit:
				printf("Thank you for your time\n");
				return 0;
				break;
			default:
				break;
		}
	}
}

ScreenView build_menu_view() {
	ScreenView output;
	ScreenLine header_line = {
		.line = "Welcome to lab 05. Please select a subprogram to run:",
		.line_length = 53,
	};
	output.header = header_line;

	output.content_length = 4;
	output.content = malloc(sizeof(ScreenView) * output.content_length);

	ScreenLine line_0 = {
		.line = "\t 1: Prime",
		.line_length = 10,
	};
	output.content[0] = line_0;

	ScreenLine line_1 = {
		.line = "\t 2: Prime Counter",
		.line_length = 18,
	};
	output.content[1] =line_1;

	ScreenLine line_2 = {
		.line = "\t 3: Factorize",
		.line_length = 14,
	};
	output.content[2] = line_2;

	ScreenLine line_3 = {
		.line = "\t 4: Exit",
		.line_length = 8,
	};
	output.content[3] = line_3;

	ScreenLine selection = {
		.line = "Selection: ",
		.line_length = 11,
	};
	output.user_input_prompt = selection;
	return output;
}

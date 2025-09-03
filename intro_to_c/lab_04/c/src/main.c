/*
 * Lab 04 - The main objective of this lab is to be able to run multiple basic user IO operations.
 * The application contains 4 subprograms that have unrelated behavior but live together for the sake
 * of user convience
 */

#include <stdio.h>
#include <stdlib.h>

#include "main.h"
#include "floor.h"
#include "even_or_odd.h"
#include "squaring.h"
#include "overtime.h"
#include "screen_writer.h"

ScreenView build_menu_view();

int main() {
	ScreenView screen_view = build_menu_view();
	MenuOption user_menu_selection = MainMenu;

	while (1) {
		draw_screen_view(screen_view);
		scanf("%i", &user_menu_selection);
		switch (user_menu_selection) {
			case MainMenu:
				break;
			case Floor:
				run_floor();
				break;
			case EvenOrOdd:
				run_even_or_odd();
				break;
			case Squaring:
				run_squaring();
				break;
			case Overtime:
				run_overtime();
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
		.line = "Welcome to lab 04. Please select a subprogram to run:",
		.line_length = 53,
	};
	output.header = header_line;

	output.content_length = 5;
	output.content = malloc(sizeof(ScreenView) * output.content_length);

	ScreenLine line_0 = {
		.line = "\t 1: Rounding",
		.line_length = 18,
	};
	output.content[0] = line_0;

	ScreenLine line_1 = {
		.line = "\t 2: Getting Even",
		.line_length = 17,
	};
	output.content[1] =line_1;

	ScreenLine line_2 = {
		.line = "\t 3: Squaring Up",
		.line_length = 16,
	};
	output.content[2] = line_2;

	ScreenLine line_3 = {
		.line = "\t 4: Overtime",
		.line_length = 13,
	};
	output.content[3] = line_3;

	ScreenLine line_4 = {
		.line = "\t 5: Exit",
		.line_length = 8,
	};
	output.content[4] = line_4;

	ScreenLine selection = {
		.line = "Selection: ",
		.line_length = 11,
	};
	output.user_input_prompt = selection;
	return output;
}

#include <stdio.h>
#include <stdlib.h>

#include "squaring.h"
#include "screen_writer.h"

void update_user_content(ScreenView*, int);

ScreenView build_squaring_view();

void run_squaring() {
	ScreenView screen_view = build_squaring_view();
	while(1) {
		draw_screen_view(screen_view);
		int user_input = 0;
		scanf("%d", &user_input);
		if (user_input == 0) {
			break;
		}
		update_user_content(&screen_view, user_input);
	}
}

void update_user_content(ScreenView* screen_view, int user_input) {
	free(screen_view->content);

	char* row = calloc(sizeof(char), user_input);
	ScreenLine* screen_line = malloc(sizeof(ScreenLine) * user_input);
	for (int i = 0; i < user_input; i++) {
		row[i] = '$';
	}
	for (int i = 0; i < user_input; i++) {
		ScreenLine content_line = {
			.line = row,
			.line_length = user_input,
		};
		screen_line[i] = content_line;
	}

	screen_view->content_length = user_input;
	screen_view->content = screen_line;
}

ScreenView build_squaring_view() {
	ScreenView output;
	ScreenLine header_line = {
		.line = "Welcome to Squaring! Please enter an interger value to see a box of that size! Enter 0 to exit",
		.line_length = 80,
	};
	output.header = header_line;

	output.content_length = 0;
	output.content = malloc(sizeof(ScreenLine) * 0);

	ScreenLine user_input = {
		.line = " Enter value please: ",
		.line_length = 20,
	};
	output.user_input_prompt = user_input;
	return output;
}

#include <stdio.h>
#include <stdlib.h>

#include "screen_writer.h"

const char* ANSI_ESCAPE = "\033";

// Move commands
const char* MOVE_HOME = "[H";
const char* MOVE_TO_COORDINATE = "[%d;%dH";
const char* MOVE_UP = "[%dA";
const char* MOVE_DOWN = "[%dB";
const char* MOVE_RIGHT = "[%dC";
const char* MOVE_LEFT = "[%dD";
const char* START_NEXT_LINE = "[%dE";
const char* START_PREVIOUS_LINE = "[%dF";

// Clear commands
const char* CLEAR_SCREEN_FORWARD = "[0J";
const char* CLEAR_SCREEN_BACKWARD = "[1J";
const char* CLEAR_ENTIRE_SCREEN = "[2J";
const char* CLEAR_SCREEN = "[3J";

void clear_screen();
void set_cursor_coordinates(int, int);
void draw_line(ScreenLine);

void draw_screen_view(ScreenView draw_request) {
	clear_screen();
	set_cursor_coordinates(0, 0);	
	draw_line(draw_request.header);
	for (int i = 0; i < draw_request.content_length; i++) {
		draw_line(draw_request.content[i]);
	}
	printf("%s", draw_request.user_input_prompt);
}

void expand_content(ScreenView* screen_view, char* text, int text_length) {
	screen_view->content_length += 1;
	screen_view->content = realloc(
		screen_view->content, 
		sizeof(ScreenLine) * screen_view->content_length
	);
	ScreenLine updated_line = {
		.line = text,
		.line_length = text_length
	};
	screen_view->content[screen_view->content_length-1] = updated_line;
}

//TODO: Sort out the Mutex issue on free
void free_screen_content(ScreenView* screen_view) {
	for (int i = 0; i < screen_view->content_length; i++) {
		free(screen_view->content[i].line);
	}
	free(screen_view->content);
}

void set_cursor_coordinates(int x, int y) {
	char* set_coordinates[7];
	sprintf(
		set_coordinates,
		MOVE_TO_COORDINATE,
		x,
		y
	);
	printf(
		"%s%s",
		ANSI_ESCAPE,
		set_coordinates
	);
}

void clear_screen() {
	printf("%s%s", ANSI_ESCAPE, CLEAR_ENTIRE_SCREEN);
}

void draw_line(ScreenLine line) {
	printf("%s\n", line.line);
}

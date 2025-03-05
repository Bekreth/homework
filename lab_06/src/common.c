#include "common.h"

static const char* ENTRY_FORMAT = "%02d - %s %s\n";
static const char* LINE = "-------------------------\n";

Menu new_menu(
	char* title,
	int title_length,
	char** menu_options, 
	int length,
	char* cursor,
	int cursor_length
) {
	Menu menu;
	menu.title = title;
	menu.title_length = title_length;
	menu.length = length;
	menu.elements = menu_options;
	menu.cursor_enabled = false;
	menu.cursor_position = 0;
	menu.cursor_length = cursor_length;
	menu.cursor_character = cursor;
	return menu;
}

void move_cursor(Menu* menu, CursorDirection direction, int step_size) {
	unsigned int mod_step = step_size % menu->length;
	switch (direction) {
		case Up:
			menu->cursor_position = (menu->cursor_position - mod_step);
			if (menu->cursor_position < 0) {
				menu->cursor_position += menu->length;
			}
			break;
		case Down:
			menu->cursor_position = (menu->cursor_position + mod_step) % menu->length;
			break;
	}
}

void print_menu(Menu* menu) {
	printf("%s\n", menu->title);
	printf(LINE);
	for (int i = 0; i < menu->length; i++) {
		char* cursor_character = 
			(menu->cursor_enabled && menu->cursor_position == i)
			? menu->cursor_character
			: "";
		printf(
			ENTRY_FORMAT,
			i+1,
			menu->elements[i],
			cursor_character
		);
	}
}

#ifndef COMMON_H
#define COMMON_H

#include <stdbool.h>

typedef struct Menu {
	char* title;
	unsigned int title_length;
	unsigned int length;
	char** elements;
	bool cursor_enabled;
	int cursor_position;
	unsigned int cursor_length;
	char* cursor_character;
} Menu;

typedef enum CursorDirection {
	Up,
	Down
} CursorDirection;

void move_cursor(Menu*, CursorDirection, int);
Menu new_menu(char*, int, char*[], int, char*, int);
void print_menu(Menu*);

#endif

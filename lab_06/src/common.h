#ifndef COMMON_H
#define COMMON_H

#include <stdbool.h>

typedef struct Menu {
	int length;
	char* elements;
	bool cursor_enabled;
	int cursor_position;
	int cursor_length;
	char* cursor_character;
} Menu;

typedef enum CursorDirection {
	Up,
	Down
} CursorDirection;

void move_cursor(Menu*, CursorDirection, int);

#endif

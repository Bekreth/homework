#include "common.h"

void move_cursor(Menu* menu, CursorDirection direction, int step_size) {
	switch (direction) {
		case Up:
			menu->cursor_position %= (menu->cursor_position + step_size);
			break;
		case Down:
			menu->cursor_position %= (menu->cursor_position - step_size);
			break;
	}
}

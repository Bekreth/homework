#include <stdio.h>

#include "tui.h"
#include "conio.h"

#include "common.h"

#define TITLE_LENGTH 80
#define ENTRY_LENGTH 10

int main() {
	char title_text[TITLE_LENGTH] = "Lab 6: Pointers and Arrays";
	char *options[ENTRY_LENGTH] = {
		"Answers to ELEX 2205",
		"Answers to ELEX 2220",
		"Answers to MATH 2342",
		"Answers to MECH 1210",
		"Answers to PHYS 2164",
		"Answers to ROBT 1270",
		"Classic Menu Style..",
		"Cursor Menu Style...",
		"Scrolling Menu Style",
		"Condensed Menu Style"
	};
	Menu menu = new_menu(
		title_text,
		TITLE_LENGTH,
		options,
		ENTRY_LENGTH,
		"<-",
		2
	);
	print_menu(&menu);
	while(1) {
		// Speifically using the clear screen function I wrote since its based directly on
		// ANSI escape code and I know it work in Linux.  The CLS system call appears to be
		// a Windows specific function.
		handle_user_input(&menu);
		clear_screen();
		print_menu(&menu);
	}
	return 0;
}

void handle_user_input(Menu* menu) {
	while(!kbhit());
	char key_pressed = getchar();
	//char key_two = getch();
	//printf("-> %c", key_pressed);
	switch (key_pressed) {
		case 'e':
			menu->cursor_enabled = !menu->cursor_enabled;
			break;
		case 'w':
			if (menu->cursor_enabled) { 
				move_cursor(menu, Up, 1);
			}
			break;
		case 's':
			if (menu->cursor_enabled) { 
				move_cursor(menu, Down, 1);
			}
			break;
		case 'd':
			menu->selected_element = menu->cursor_position;
			break;
		case '0':
			menu->selected_element = 0;
			break;
		case '1':
			menu->selected_element = 1;
			break;
		case '2':
			menu->selected_element = 2;
			break;
		case '3':
			menu->selected_element = 3;
			break;
		case '4':
			menu->selected_element = 4;
			break;
		case '5':
			menu->selected_element = 5;
			break;
		case '6':
			menu->selected_element = 6;
			break;
		case '7':
			menu->selected_element = 7;
			break;
		case '8':
			menu->selected_element = 8;
			break;
		case '9':
			menu->selected_element = 9;
			break;
	}	
}

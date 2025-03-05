#include <stdio.h>

#include "tui.h"
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
	clear_screen();
	return 0;
}

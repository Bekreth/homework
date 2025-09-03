#ifndef MAIN_H
#define MAIN_H

typedef enum Operation {
	NONE = 0,
	FACTORIAL,
	FIBONACCI,
	RECT_TO_POLAR,
	POLAR_TO_RECT,
	EXIT
} Operation;

void print_menu();
void handle_factorial();
void handle_fibonacci();
void handle_rectangular_to_polar_conversion();
void handle_polar_to_rectangular_conversion();

#endif

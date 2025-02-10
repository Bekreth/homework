/*
 * Lab 04 - The main objective of this lab is to be able to run multiple basic user IO operations.
 * The application contains 4 subprograms that have unrelated behavior but live together for the sake
 * of user convience
 */

#include <stdio.h>

#include "main.h"
#include "floor.h"
#include "even_or_odd.h"
#include "squaring.h"
#include "overtime.h"

int main() {
	printf("Welcome to lab 04\n");
	MenuOption user_menu_selection = MainMenu;
	while (1) {
		user_menu_selection = fetch_user_menu_selection();
		switch (user_menu_selection) {
			case MainMenu:
				break;
			case Floor:
				printf("\n");
				run_floor();
				break;
			case EvenOrOdd:
				printf("\n");
				run_even_or_odd();
				break;
			case Squaring:
				printf("\n");
				run_squaring();
				break;
			case Overtime:
				break;
			case Exit:
				printf("Thank you for your time\n");
				return 0;
				break;
		}
	}
}

MenuOption fetch_user_menu_selection() {
	printf("Please select a subprogram to run:\n");
	printf("\t 1: Rounding\n");
	printf("\t 2: Getting Even\n");
	printf("\t 3: Squaring Up\n");
	printf("\t 4: Overtime\n");
	printf("\t 5: Exit\n");
	MenuOption output = MainMenu;

	//TODO: Check behavior if the input is invalid
	scanf("%i", &output);
	return output;
}

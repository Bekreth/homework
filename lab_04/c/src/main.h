#ifndef MAIN_H
#define MAIN_H

typedef enum MenuOption {
	MainMenu,
	Floor,
	EvenOrOdd,
	Squaring,
	Overtime,
	Exit
} MenuOption ;

MenuOption fetch_user_menu_selection();

#endif

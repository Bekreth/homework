#include <stdio.h>

#include "even_or_odd.h"

const char* EVEN_ODD_FORMATTING_TEMPLATE = "|%-5s|%-10d|";

void introduce_even_or_odd();
int is_even(int);

void run_even_or_odd() {
	introduce_even_or_odd();
	while (1) {
		int user_input = 0;
		printf("Enter value please: ");
		scanf("%d", &user_input);
		if (user_input == 0) {
			break;
		}
		if (is_odd(user_input)) {
			printf(EVEN_ODD_FORMATTING_TEMPLATE, "Odd", user_input);
		} else {
			printf(EVEN_ODD_FORMATTING_TEMPLATE, "Even", user_input);
		}
	}
	printf("Thank you for playing even odd!\n");
}

void introduce_even_or_odd() {
	printf("Welcome to Getting Even! Input a number an be told whether its even or odd. Enter 0 to exit\n\n");
	printf("--------------------------------------------------------\n");
	printf("|Even? |User value|\n");
}

int is_odd(int user_input) {
	return user_input % 2;
}

/**
The golfed solution is as follows. I will not run code through this.
int o(int i){return i%2;}
 */

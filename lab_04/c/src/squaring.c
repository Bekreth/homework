#include <stdio.h>

#include "squaring.h"

void introduce_squaring();
void draw_box(int);

void run_squaring() {
	introduce_squaring();
	while(1) {
		int user_input = 0;
		printf("Enter value please: ");
		scanf("%d", &user_input);
		if (user_input == 0) {
			break;
		}
		draw_box(user_input);
	}
}

void introduce_squaring() {
	printf("Welcome to Squaring! Please enter an interger value to see a box of that size! Enter 0 to exit\n\n");
}

void draw_box(int user_input) {
	char *row = malloc(sizeof(char) * user_input);
	for (int i = 0; i < user_input; i++) {
		row[i] = '$';
	}
	for (int i = 0; i < user_input; i++) {
		printf("%s\n", row);
	}
}

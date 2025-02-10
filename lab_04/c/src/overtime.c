#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "overtime.h"
#include "user_time.h"

void introduce_overtime();
UserTime get_user_input();

void run_overtime() {
	introduce_overtime();
	while(1) {
		UserTime user_input_1 = get_user_input(1);
		if (is_zero(&user_input_1)) {
			break;
		}

		UserTime user_input_2 = get_user_input(2);
		if (is_zero(&user_input_2)) {
			break;
		}

		char* time_string_1 = to_string(&user_input_1);
		char* time_string_2 = to_string(&user_input_2);
		printf(
			"%d seconds have passed since %s and %s\n",
			calculate_delta_seconds(&user_input_1, &user_input_2),
			time_string_1,	
			time_string_2
		);
		free(time_string_1);
		free(time_string_2);
	}
}

void introduce_overtime() {
	printf("Welcome to Overtime! Input a number an be told whether its even or odd. Enter 0 to exit\n\n");
}

UserTime get_user_input(int counter) {
	printf("Enter time %d (hh:mm:ss): ", counter);
	UserTime user_input;
	scanf(
		"%d:%d:%d", 
		&user_input.hours,
		&user_input.minutes,
		&user_input.seconds
	);
	return user_input;
}

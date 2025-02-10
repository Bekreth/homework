#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "user_time.h"

int to_seconds(UserTime*);

bool is_zero(UserTime* user_input) {
	return user_input->hours == 0 && 
		user_input->minutes == 0 && 
		user_input->seconds == 0;
}

char* to_string(UserTime* input) {
	char* output = malloc(sizeof(char) * 8);
	sprintf(
		output, 
		"%02d:%02d:%02d", 
		input->hours,
		input->minutes,
		input->seconds
	);
	return output;
}

int calculate_delta_seconds(
	UserTime* user_time_1, 
	UserTime* user_time_2
) {
	int time_1_seconds = to_seconds(user_time_1);
	int time_2_seconds = to_seconds(user_time_2);
	if (time_2_seconds > time_1_seconds) {
		// add 12 hours if time 1 is less than time 2
		time_1_seconds += 12*3600;
	}
	return time_1_seconds - time_2_seconds;	
}

int to_seconds(UserTime* input) {
	return *(&input->hours)*3600 +
		*(&input->minutes)*60 +
		*(&input->seconds);
}

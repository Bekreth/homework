#ifndef USER_TIME_H
#define USER_TIME_H

typedef struct UserTime {
	int seconds;
	int minutes;
	int hours;
} UserTime;

char* to_string(UserTime*); 
bool is_zero(UserTime*);
int calculate_delta_seconds(UserTime*, UserTime*);

#endif

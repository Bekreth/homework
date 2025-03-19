#ifndef SCARA_STATE_H
#define SCARA_STATE_H

#include <stdbool.h>

typedef enum MotorSpeed {
	High,
	Medium,
	Low
} MotorSpeed;


typedef struct Scara {
	double theta_1;
	double theta_2;
	bool is_pen_down;
	MotorSpeed speed;
} Scara;


#endif



#ifndef COMMANDS_H
#define COMMANDS_H

#include "kinematics.h"

void enable_color_cycling();
void disable_color_cycling();

// TODO: Add TCP connection
void send_state(Scara*);

typedef struct Command {
	char* text;
	int length;	
} Command;


Command pen_up();
Command pen_down();
Command pen_color(int8_t red, int8_t green, int8_t blue);

#endif


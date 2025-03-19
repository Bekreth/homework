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

#endif


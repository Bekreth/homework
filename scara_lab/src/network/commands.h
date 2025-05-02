#ifndef COMMANDS_H
#define COMMANDS_H

#include <stdbool.h>
#include <stdint.h>

#include "kinematics.h"

typedef struct Command {
	int length;	
	char* text;
} Command;

typedef struct Commands {
	int length;
	Command* commands;
} Commands;

// Pen Commands
Command pen_up();
Command pen_down();
Command pen_color(uint8_t red, uint8_t green, uint8_t blue);
Command cycle_pen_color(bool enable);

// Movement Commands
Command rotate_joint(float angle_1, float angle_2);
Command home();
Command end();

// Simulator Metacommands
Command clear_trace();
Command clear_log();
Command simulator_shutdown();

#endif


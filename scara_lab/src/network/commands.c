#include <stdlib.h>
#include <stdio.h>

#include "commands.h"

const char* motor_speed_strings[] = { "HIGH", "MEDIUM", "LOW" };

// Pen Commands
Command pen_up() {
	Command output = {
		.text = "PEN_UP\n",
		.length = 7
	};
	return output;
}

Command pen_down() {
	Command output = {
		.text = "PEN_DOWN\n",
		.length = 9
	};
	return output;
}

const char* PEN_COLOR_FORMAT = "PEN_COLOR %u %u %u\n";
Command pen_color(uint8_t red, uint8_t green, uint8_t blue) {
	int length = 23;
	char* text = malloc(sizeof(char) * length);
	sprintf(text, PEN_COLOR_FORMAT, red, green, blue);
	Command output = {
		.text = text,
		.length = length
	};
	return output;
}

Command cycle_pen_color(bool enable) {
	Command output = {
		.text = enable ?  "CYCLE_PEN_COLORS ON\n" :  "CYCLE_PEN_COLORS OFF\n",
		.length = enable ? 20 : 21
	};
	return output;
}

// Movement Commands
// TODO: Does this exist?
// const char* MOTOR_SPEED = "MOTOR_SPEED %s\n";
const char* ROTATE_JOINT_FORMAT = "ROTATE_JOINT ANG1 %-3.2f ANG2 %-3.2f\n";
Command rotate_joint(float angle_1, float angle_2) {
	int length = 37;
	char* text = malloc(sizeof(char) * length);
	sprintf(text, ROTATE_JOINT_FORMAT, angle_1, angle_2);
	Command output = {
		.text = text,
		.length = length
	};
	return output;
}

Command home() {
	Command output = {
		.text = "HOME\n",
		.length = 5
	};
	return output;
}

Command end() {
	Command output = {
		.text = "END\n",
		.length = 4
	};
	return output;
}

// Simulator Metacommands
Command clear_trace() {
	Command output = {
		.text = "CLEAR_TRACE\n",
		.length = 12
	};
	return output;
}

Command clear_log() {
	Command output = {
		.text = "CLEAR_LOG\n",
		.length = 10
	};
	return output;
}

Command shutdown_simulator() {
	Command output = {
		.text = "SHUTDOWN_SIMULATION\n",
		.length = 20
	};
	return output;
}

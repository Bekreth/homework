#include "commands.h"

const char* motor_speed_strings[] = { "HIGH", "MEDIUM", "LOW" };

Command pen_up() {
	Command output = {
		.text = "PEN_UP\n",
		.length = 7
	};
	return output
}

Command pen_down() {
	Command output = {
		.text = "PEN_DOWN\n",
		.length = 9
	};
	return output;
}

const char* PEN_COLOR_FORMAT = "PEN_COLOR %-2u %-2u %-2u\n";
Command pen_color(char red, char green, char blue) {
	char* format = malloc((char) * 22);
	sprintf(PEN_COLOR_FORMAT, red, green, blue);
	Command output = {
		.text = sprintf(PEN_COLOR_FORMAT, red, green, blue),
		.length = 22
	};
	return output;
}


const char* CYCLE_PEN_COLORS = "CYCLE_PEN_COLORS %s\n";
const char* ROTATE_JOINT = "ROTATE_JOINT ANG1 %.2f ANG2 %.2f\n";
const char* CLEAR_TRACE = "CLEAR_TRACE\n";
const char* CLEAR_LOG = "CLEAR_LOG\n";
const char* SHUTDOWN_SIMULATION = "SHUTDOWN_SIMULATION\n";
const char* MOTOR_SPEED = "MOTOR_SPEED %s\n";
const char* HOME = "HOME\n";
const char* END = "END\n";

Scara previous_state = {
	.theta_1 = 0.0,
	.theta_2 = 0.0,
	.is_pen_down = false
};

bool cycling_pen_colors = false;

void enable_color_cycling() {
	cycling_pen_colors = true;
}

void disable_color_cycling() {
	cycling_pen_colors = false;
}




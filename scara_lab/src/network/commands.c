#include "commands.h"

const char* motor_speed_strings[] = { "HIGH", "MEDIUM", "LOW" };

const char* PEN_UP = "PEN_UP";
const char* PEN_DOWN = "PEN_DOWN";
const char* PEN_COLOR = "PEN_COLOR %u %u %u";
const char* CYCLE_PEN_COLORS = "CYCLE_PEN_COLORS %s";
const char* ROTATE_JOINT = "ROTATE_JOINT ANG1 %f ANG2 %f";
const char* CLEAR_TRACE = "CLEAR_TRACE";
const char* CLEAR_LOG = "CLEAR_LOG";
const char* SHUTDOWN_SIMULATION = "SHUTDOWN_SIMULATION";
const char* MOTOR_SPEED = "MOTOR_SPEED %s";
const char* HOME = "HOME";
const char* END = "END";

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




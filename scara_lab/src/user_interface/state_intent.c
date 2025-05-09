#include "user_interface.h"
#include "network.h"
#include "state_intent.h"
#include "validate_number.h"

Intent process_pen_up(Tokens* tokens) {
	Intent output;
	if (tokens->length != 1) {
		output.error = bad_argument_count();
		return output;
	}
	Command* pen_commands = malloc(sizeof(Command));
	pen_commands[0] = pen_up();
	Commands commands = {
		.length = 1,
		.commands = pen_commands
	};
	output.commands = commands;
	return output;
}

Intent process_pen_down(Tokens* tokens) {
	Intent output;
	if (tokens->length != 1) {
		output.error = bad_argument_count();
		return output;
	}
	Command* pen_commands = malloc(sizeof(Command));
	pen_commands[0] = pen_down();
	Commands commands = {
		.length = 1,
		.commands = pen_commands
	};
	output.commands = commands;
	return output;
}

Intent process_pen_color(Tokens* tokens) {
	Intent output;
	if (tokens->length != 4) {
		output.error = bad_argument_count();
		return output;
	}
	for (int i = 1; i <= 3; i ++) {
		if (!valid_int_input(tokens->tokens[1])) {
			output.error = invalid_numeric_input();
			return output;
		}
	}
	uint8_t red = (uint8_t) atoi(tokens->tokens[1]);
	uint8_t green = (uint8_t) atoi(tokens->tokens[2]);
	uint8_t blue = (uint8_t) atoi(tokens->tokens[3]);

	Command* pen_color_command = malloc(sizeof(Command));
	pen_color_command[0] = pen_color(red, green, blue);
	Commands commands = {
		.length = 1,
		.commands = pen_color_command
	};
	output.commands = commands;
	return output;
}

Intent process_speed(Tokens* tokens) {
	Intent output;
	if (tokens->length != 2) {
		output.error = bad_argument_count();
		return output;
	}
	Command* motor_command = malloc(sizeof(Command));
	switch (tokens->tokens[1][0]) {
		case 'h':
		case 'H':
			// TODO:
			motor_command[0] = set_motor_speed(High);
			break;
		case 'm':
		case 'M':
			motor_command[0] = set_motor_speed(Medium);
			break;
		case 'l':
		case 'L':
			motor_command[0] = set_motor_speed(Low);
			break;
		default:
			output.error = invalid_motor_speed();
			break;
	}
	Commands commands = {
		.length = 1,
		.commands = motor_command
	};
	output.commands = commands;
	return output;
}

Intent process_quit() {
	Intent output = {
		.error = {
			.error_code = 100,
			.error_message= "Closing"
		}
	};
	return output;
}


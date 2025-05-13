#include <stdlib.h>

#include "user_interface.h"
#include "network.h"
#include "state_intent.h"
#include "validate_number.h"

Intent process_pen_up(Tokens* tokens) {
	Intent output = new_intent();
	if (tokens->length != 1) {
		output.error = bad_argument_count();
		return output;
	}
	Commands commands = new_commands();
	add_command(&commands, pen_up());
	output.commands = commands;
	return output;
}

Intent process_pen_down(Tokens* tokens) {
	Intent output = new_intent();
	if (tokens->length != 1) {
		output.error = bad_argument_count();
		return output;
	}
	Commands commands = new_commands();
	add_command(&commands, pen_down());
	output.commands = commands;
	return output;
}

Intent process_pen_color(Tokens* tokens) {
	Intent output = new_intent();
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

	Commands commands = new_commands();
	add_command(&commands, pen_color(red, green, blue));
	output.commands = commands;
	return output;
}

Intent process_speed(Tokens* tokens) {
	Intent output = new_intent();
	if (tokens->length != 2) {
		output.error = bad_argument_count();
		return output;
	}
	Commands commands = new_commands();
	switch (tokens->tokens[1][0]) {
		case 'h':
		case 'H':
			// TODO:
			add_command(&commands, set_motor_speed(High));
			break;
		case 'm':
		case 'M':
			add_command(&commands, set_motor_speed(Medium));
			break;
		case 'l':
		case 'L':
			add_command(&commands, set_motor_speed(Low));
			break;
		default:
			output.error = invalid_motor_speed();
			break;
	}
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


#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "network.h"
#include "intent_parser.h"

IntentError bad_argument_count();

Intent process_move_j(Tokens*);
Intent process_move_l(Tokens*);

Intent process_pen_up(Tokens*);
Intent process_pen_down(Tokens*);
Intent process_pen_color(Tokens*);

Intent process_speed(Tokens*);

Intent process_quit();


Intent parse_tokens(Tokens* tokens) {
	Intent output;
	char* token = tokens->tokens[0]; 
	if (strcmp(token, "movScaraJ") == 0) {
		output = process_move_j(tokens);
	} else if (strcmp(token, "movScaraL") == 0) {
		output = process_move_l(tokens);
	} else if (strcmp(token, "scaraPenUp") == 0) {
		output = process_pen_up(tokens);
	} else if (strcmp(token, "scaraPenDown") == 0) {
		output = process_pen_down(tokens);
	} else if (strcmp(token, "scaraSpeed") == 0) {
		output = process_speed(tokens);
	} else if (strcmp(token, "scaraPenColor") == 0) {
		output = process_pen_color(tokens);
	} else if (strcmp(token, "quit") == 0) {
		output = process_quit();
	} else {
		IntentError error = {
			.error_code = 2,
			.error_message = "Unrecognized command"
		};
		output.error = error;
	}
	return output;
}

IntentError bad_argument_count() {
	IntentError output = {
		.error_code = 1,
		.error_message = "Recieved the wrong number of arguments"
	};
	return output;
}

Intent process_move_j(Tokens* tokens) {
	Intent output;
	if (tokens->length != 3) {
		output.error = bad_argument_count();
		return output;
	}
	//TODO
}

Intent process_pen_up(Tokens* tokens) {
	Intent output;
	if (tokens->length != 1) {
		output.error = bad_argument_count();
		return output;
	}
	Command pen_commands[0] = {pen_up()};
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
	Command pen_commands[0] = {pen_down()};
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
	uint8_t red = (uint8_t) atoi(tokens->tokens[1]);
	uint8_t green = (uint8_t) atoi(tokens->tokens[2]);
	uint8_t blue = (uint8_t) atoi(tokens->tokens[3]);

	if (red == 0 || green == 0 || blue == 0) {
		IntentError bad_colors = {
			.error_code = 3,
			.error_message = "Expect a numerical value and did not recieve one"
		};
		output.error = bad_colors;
		return output;
	}

	Command pen_color_command[0] = {pen_color(red, green, blue)};
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
	Commands commands;
	commands.length = 1;
	Command motor_command[0];
	switch (tokens->tokens[1][0]) {
		case 'h':
		case 'H':
			motor_command[0] = motor_speed(High);
			break;
		case 'm':
		case 'M':
			motor_command[0] = motor_speed(Medium);
			break;
		case 'l':
		case 'L':
			motor_command[0] = motor_speed(Low);
			break;
		default:
			IntentError error = {
				.error_code = 4,
				.error_message = "Invalid motor speed provided"
			};
			output.error = error;
			break;
	}
	commands.commands = motor_command;
	output.commands = commands;
	return output;
}

Intent process_quit() {
	Intent output = {
		.error = {
			.error_code = 0,
			.error_message= "Closing"
		}
	};
	return output;
}

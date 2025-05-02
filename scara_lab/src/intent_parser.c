#include <stdlib.io>
#include <stdint.h>

#include "commands.h"
#include "intent_parser.h"

IntentError bad_argument_count();

Intent process_move_j(Tokens*);
Intent process_move_l(Tokens*);

Intent process_pen_up(Tokens*);
Intent process_pen_down(Tokens*);
Intent process_pen_color(Tokens*);

Intent process_quit();

Intent parse_tokens(Tokens* tokens) {
	Intent output;
	switch (*(tokens->tokens[0])) {
		case "movScaraJ"
			if (tokens->length != 3) {
				output = {
					.error = bad_argument_count();
				}
			}
			break;

		case "movScaraL"
			if (tokens->length != 6) {
				output = {
					.error = bad_argument_count();
				}
			}
			break;

		case "scaraPenUp"
			process_pen_up(tokens);
			break;

		case "scaraPenDown"
			process_pen_up(tokens);
			break;

		case "scaraSpeed"
			if (tokens->length != 2) {
				output = {
					.error = bad_argument_count();
				}
			}
			//TODO:
			break;

		case "scaraPenColor"
			output = process_pen_color(tokens);
			break;
			
		case "quit"
			output = process_quit();
			break;

		default:
			output = {
				.error = {
					.error_code = 2;
					.error_message = "Unrecognized command";
				};
			}
			break;
	}
	return output;
}

IntentError bad_argument_count() {
	IntentError output = {
		.error_code = 1;
		.error_message = "Recieved the wrong number of arguments";
	};
	return ouput;
}

Intent process_pen_up(Tokens* tokens) {
	Intent output;
	if (tokens->length != 1) {
		output = {
			.error = bad_argument_count();
		}
	}
	output = {
		.commands = {
			.length = 1;
			.commands = {pen_up()};
		}
	}
	return output;
}


Intent process_pen_down(Tokens* tokens) {
	Intent output;
	if (tokens->length != 1) {
		output = {
			.error = bad_argument_count();
		}
	}
	output = {
		.commands = {
			.length = 1;
			.commands = {pen_down()};
		}
	}
	return output;
}

Intent process_pen_color(Tokens* tokens) {
	Intent output;
	if (tokens->length != 4) {
		output = {
			.error = bad_argument_count();
		}
	}
	uint8_t red = (uint8_t) atoi(tokens->tokens[1]);
	uint8_t green = (uint8_t) atoi(tokens->tokens[2]);
	uint8_t blue = (uint8_t) atoi(tokens->tokens[3]);

	if (red == 0 || green == 0 || blue == 0) {
		output = {
			.error = {
				.error_code = 3;
				.error_message = "Expect a numerical value and did not recieve one";
			};
		};
	}

	output = {
		.commands = {
			.length = 1;
			.commands = {
				pen_color(red, green, blue)
			};
		}
	}
	return output;
}

Intent process_quit() {
	Intent output;
	output = {
		.error = {
			.error_code = 0;
			.error_message= "Closing";
		};
	};
	return output;
}

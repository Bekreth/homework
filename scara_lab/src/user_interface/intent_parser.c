#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#include "network.h"
#include "kinematics.h"

#include "intent_parser.h"
#include "intent_error.h"
#include "motion_intent.h"
#include "state_intent.h"


Intent parse_tokens(Tokens* tokens, Handedness handedness) {
	Intent output;
	char* token = tokens->tokens[0]; 
	if (strcmp(token, "moveScaraJ") == 0) {
		output = process_move_j(tokens, handedness);
	} else if (strcmp(token, "moveScaraL") == 0) {
		output = process_move_l(tokens, handedness);
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
		output.error = unrecognized_command();
	}
	return output;
}

Intent new_intent() {
	IntentError error = {
		.error_code = 0,
		.error_message = ""
	};
	Commands commands = {
		.length = 0,
		.commands = NULL
	};
	Intent output = {
		.error = error,
		.commands = commands	
	};
	return output;
}


#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "network.h"

#include "validate_number.h"
#include "intent_parser.h"
#include "motion_intent.h"


Intent process_move_j(Tokens* tokens, Handedness current_hand) {
	Intent output = new_intent();
	if (tokens->length != 3) {
		output.error = bad_argument_count();
		return output;
	} 
	for (int i = 1; i <= 2; i ++) {
		if (!valid_float_input(tokens->tokens[i])) {
			output.error = invalid_numeric_input();
			return output;
		}
	}
	float x_pos = atof(tokens->tokens[1]);
	float y_pos = atof(tokens->tokens[2]);

	float angle_0 = 0.0;
	float angle_1 = 0.0;
	if (
		calculate_scara_ik(x_pos, y_pos, &angle_0, &angle_1, current_hand) ||
		calculate_scara_ik(x_pos, y_pos, &angle_0, &angle_1, opposite_hand(current_hand))
	) {
		float degree_0 = 180.0 * angle_0 / M_PI;
		float degree_1 = 180.0 * angle_1 / M_PI;
		Command* move_command = malloc(sizeof(Command));
		move_command[0] = rotate_joint(degree_0, degree_1);
		Commands out_commands = {
			.length = 1,
			.commands = move_command
		};
		output.commands = out_commands;
	} else {
		output.error = out_of_range();
	}
	return output;	
}

Intent process_move_l(Tokens* tokens, Handedness current_hand) {
	Intent output = new_intent();
	if (tokens->length != 6) {
		output.error = bad_argument_count();
		return output;
	}
	for (int i = 1; i <= 4; i ++) {
		if (!valid_float_input(tokens->tokens[i])) {
			output.error = invalid_numeric_input();
			return output;
		}
	}
	if (!valid_int_input(tokens->tokens[5])) {
		output.error = invalid_numeric_input();
		return output;
	}
	float x0_pos = atof(tokens->tokens[1]);
	float y0_pos = atof(tokens->tokens[2]);
	float x1_pos = atof(tokens->tokens[3]);
	float y1_pos = atof(tokens->tokens[4]);
	int subdivisions = atoi(tokens->tokens[5]);
}

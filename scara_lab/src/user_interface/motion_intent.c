#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "network.h"
#include "path_planner.h"
#include "kinematics.h"

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
		Commands commands = new_commands();
		add_command(&commands, rotate_joint(angle_0, angle_1));
		output.commands = commands;
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

	Coordinates points_along_path = divide_path(
		new_coordinate(x0_pos, y0_pos),
		new_coordinate(x1_pos, y1_pos),
		subdivisions
	);
	PossiblePathings pathings = create_possible_paths(points_along_path);
	int length = 0;
	int capacity = pathings.length;
	Commands commands = new_commands();

	Coordinate current_coordinate = {
		.x_pos = -999.0,
		.y_pos = -999.0
	};

	float angle_0 = 0.0;
	float angle_1 = 0.0;

	for (int i = 0; i < pathings.length; i++) {
		PossiblePathing pathing = pathings.pathings[i];

		bool at_starting_coordinate = coordinates_equal(current_coordinate, pathing.starting_coordinate);

		bool created_command = false;

		// Set Initial poisition
		if (!at_starting_coordinate) {
			created_command = calculate_scara_ik(
				pathing.starting_coordinate.x_pos, pathing.starting_coordinate.y_pos,
				&angle_0, &angle_1, current_hand
			);
			if (!created_command) {
				current_hand = opposite_hand(current_hand);
				created_command = calculate_scara_ik(
					pathing.starting_coordinate.x_pos, pathing.starting_coordinate.y_pos,
					&angle_0, &angle_1, current_hand
				);
			}
			if (created_command) {
				add_command(&commands, pen_up());
				add_command(&commands, rotate_joint(angle_0, angle_1));
				add_command(&commands, pen_down());
				current_coordinate = pathing.starting_coordinate;
			}

		}


		created_command = calculate_scara_ik(
			pathing.ending_coordinate.x_pos, pathing.ending_coordinate.y_pos,
			&angle_0, &angle_1, current_hand
		);
		if (created_command) {
			add_command(&commands, rotate_joint(angle_0, angle_1));
			current_coordinate = pathing.ending_coordinate;
		} else {
			// NOOP : Falied to move to coordinate\n
		}
	}
	output.commands = commands;
	return output;
}

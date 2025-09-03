#include <stdlib.h>
#include <stdbool.h>

#include "path_planner.h"
#include "kinematics.h"

bool crosses_critical_boundary(Quadrant, Quadrant);
bool coordinate_is_accessible(Coordinate, Handedness);
PossiblePathings one_quadrant_pathing(Coordinates);
PossiblePathings multi_quadrant_pathing(Coordinates);
PossiblePathings critical_quadrant_pathing(Coordinates);

Coordinates divide_path(
	Coordinate starting_position, 
	Coordinate ending_position,
	int intermediate_points
) {
	int length = intermediate_points + 2;
	float delta_x = ending_position.x_pos - starting_position.x_pos;
	float delta_y = ending_position.y_pos - starting_position.y_pos;

	float offset_x = delta_x / (intermediate_points + 1);
	float offset_y = delta_y / (intermediate_points + 1);

	Coordinate* targets = malloc(sizeof(Coordinate) * length);

	for (int i = 0; i < length; i++) {
		targets[i].x_pos = starting_position.x_pos + offset_x * i;
 		targets[i].y_pos = starting_position.y_pos + offset_y * i;
	}
	Coordinates output = {
		.length = length,
		.coordinates = targets
	};
	return output;
}

PossiblePathings create_possible_paths(Coordinates coordinates) {
	int length = coordinates.length - 1;
	PossiblePathing* pathings = malloc(sizeof(PossiblePathing) * length);
	float dead_point_0 = 0.0;
	float dead_point_1 = 0.0;

	for (int i = 0; i < length; i++) {
		Coordinate starting_coordinate = coordinates.coordinates[i];
		Coordinate ending_coordinate = coordinates.coordinates[i + 1];
		PossiblePathing pathing = {
			.starting_coordinate = starting_coordinate,
			.ending_coordinate = ending_coordinate,
			.is_right_handed = false,
			.is_left_handed = false
		};
		pathings[i] = pathing;
		if (
			coordinate_is_accessible(starting_coordinate, Left) && 
			coordinate_is_accessible(ending_coordinate, Left)
		) {
			pathings[i].is_left_handed = true;
		}
		if (
			coordinate_is_accessible(starting_coordinate, Right) && 
			coordinate_is_accessible(ending_coordinate, Right)
		) {
			pathings[i].is_left_handed = true;
		}
	}
	PossiblePathings output = {
		.length = length,
		.pathings = pathings
	};
	return output;
}

bool coordinate_is_accessible(Coordinate coordinate, Handedness handedness) {
	float dead_point_0 = 0.0;
	float dead_point_1 = 0.0;
	return calculate_scara_ik(coordinate.x_pos, coordinate.y_pos, &dead_point_0, &dead_point_1, handedness);
}

bool crosses_critical_boundary(Quadrant q0, Quadrant q1) {
	return (q0 == Q2 && q1 == Q3) || (q0 == Q3 && q1 == Q2);
}

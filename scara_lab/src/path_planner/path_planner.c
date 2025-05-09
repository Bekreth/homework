#include <stdbool.h>

#include "path_planner.h"

bool crosses_critical_boundary(Coordinate, Coordinate);

Coordinates divide_path(Coordinate starting_position, Coordinate ending_position, int intermediate_points) {
	float delta_x = ending_position.x_pos - starting_position.x_pos;
	float delta_y = ending_position.y_pos - starting_position.y_pos;

	float offset_x = delta_x / (intermediate_points + 2);
	float offset_y = delta_y / (intermediate_points + 2);

	Coordinate* targets = malloc(sizeof(Coordinate) * (intermediate_points + 2));

	for (int i = 0; i < intermediate_points + 2; i++) {
		targets[i].x_pos = starting_position.x_pos + offset_x * i;
 		targets[i].y_pos = starting_position.y_pos + offset_y * i;
	}
	Coordinates output = {
		.length = intermediate_points + 2,
		.coordinates = targets
	};
	return output;
}

PossiblePathings create_possible_paths(Coordinates coordinates) {
	int length = 0;
	int capacity = coordinates.length + 1;
	float dead_point_0 = 0.0;
	float dead_point_1 = 0.0;

	for (int i = 0; i < coordinates.length - 1; i++) {
		Coordinate starting_position = coordinates.coordinates[i];
		Coordinate ending_position = coordinates.coordinates[i + 1];

		
	}

}

bool crosses_critical_boundary(Coordinate starting_coordinate, Coordinate ending_coordinate) {

}

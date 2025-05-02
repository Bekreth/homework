#include "path.h"

void divide_path(
	Coordinate starting_position, Coordinate ending_position, 
	int intermediate_points, Coordinate** targets
) {
	float delta_x = ending_position.x_pos - starting_position.x_pos;
	float delta_y = ending_position.y_pos - starting_position.y_pos;

	float offset_x = delta_x / (intermediate_points + 2);
	float offset_y = delta_y / (intermediate_points + 2);

	for (int i = 0; i < intermediate_points + 2; i++) {
		targets[i]->x_pos = starting_position.x_pos + offset_x * i;
 		targets[i]->y_pos = starting_position.y_pos + offset_y * i;
	}

}


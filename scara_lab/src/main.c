#include <stdbool.h>

#include "scara_lab.h"
#include "network.h"
#include "commands.h"

int main() {
	create_connection();

	float angle_1;
	float angle_2;
	float x_pos;
	float y_pos;

	printf("Starting FK.  Enter 360,360 to exit\n");
	while (true) {
		printf("Submit angles XXX.XX,YYY.YY: ");
		scanf("%f,%f", &angle_1, &angle_2);
		if (angle_1 == 360) {
			break;
		}
		int error_code = calculate_scara_fk(angle_1, angle_2, &x_pos, &y_pos);
		if (error_code == 1) {
			printf("Major angle is out of bounds\n");
			continue;
		} else if (error_code == 2) {
			printf("Minor angle is out of bounds\n");
			continue;
		} else {
			Command commands_fk[1] = { rotate_joint(angle_1, angle_2) };
			send_commands(commands_fk, 1);
		}
	}


	printf("Starting IK.  Enter 999,999 to exit\n");
	while (true) {
		char handedness_char = '0';
		printf("Submit handedness and position:  {LR},XXX.XX,YYY.YY: ");
		scanf(" %c,%f,%f", &handedness_char, &x_pos, &y_pos);
		if (&x_pos == 999) {
			break;
		}

		bool successful_path = false;
		if (handedness_char == 'L' || handedness_char == 'l') {
			successful_path = calculate_scara_ik(x_pos, y_pos, &angle_1, &angle_2, Left);
		} else if (handedness_char == 'R' || handedness_char == 'r') {
			successful_path = calculate_scara_ik(x_pos, y_pos, &angle_1, &angle_2, Right);
		} else {
			printf("Improper handedness\n");
			continue;
		}

		if (!successful_path) {
			printf("Coordinates out of bounds\n");
			continue;
		}

		Command commands[1] = { rotate_joint(angle_1, angle_2) };
		send_commands(commands, 1);
	}

	destroy_connection();
	return 0;
}

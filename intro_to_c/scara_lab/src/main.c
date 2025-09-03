#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#include "scara_lab.h"
#include "network.h"
#include "user_interface.h"

char* read_user_input();

int main() {
	ScaraRobot robot = new_scara_robot();
	create_connection();

	while (true) {
		printf("\nSCARA Driver > ");
		char user_input[1000];
		gets(user_input);
		Tokens tokens = new_tokens();
		char* delimiter = " ";
		char* tokenized = strtok(user_input, delimiter);
		while (tokenized != NULL) {
			add_token(&tokens, tokenized);
			tokenized = strtok(NULL, delimiter);
		}

		Intent intent = parse_tokens(&tokens, robot.handedness);
		if (intent.error.error_code != 0) {
			if (intent.error.error_code == 100) {
				printf("Closing SCARA Driver. Thank you\n");
				sleep(2);
				break;
			} else {
				printf(
					"Unable to process command due to error [%d]: %s\n",
					intent.error.error_code,
					intent.error.error_message
				);
				continue;
			}
		}
		send_commands(intent.commands);
	}

	destroy_connection();
	return 0;
}

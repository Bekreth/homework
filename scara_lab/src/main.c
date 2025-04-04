#include "scara_lab.h"

#include "network.h"
#include "commands.h"

int main() {
	create_connection();

	Command commands[3] = {
		pen_up(),
		pen_down(),
		rotate_joint(30.0, 25.0),
	};
	send_commands(commands, 3);
	destroy_connection();
	return 0;
}

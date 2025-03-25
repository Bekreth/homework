#include "scara_lab.h"

#include "network.h"
#include "commands.h"

int main() {
	create_connection();

	Command commands[2] = {
		pen_down(),
		pen_up(),
		pen_color(64, 128, 76),
	};
	send_commands(commands, 2);
	return 0;
}

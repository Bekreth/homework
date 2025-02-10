#include <stdio.h>

const char* ANSI_ESCAPE = "\033";
const char* COLOR_START = "[31;1;4m";
const char* COLOR_END = "[0m";
const char* CLEAR_SCREEN = "[2J";
const char* HOME = "[H";

int main() {

	char* message = "Hello world";

	printf(
		"%s%s\n",
		ANSI_ESCAPE,
		CLEAR_SCREEN
	);

	printf(
		"%s%s\n",
		ANSI_ESCAPE,
		HOME
	);

	printf(
		"%s%s%s%s%s\n",
		ANSI_ESCAPE,
		COLOR_START,
		message,
		ANSI_ESCAPE,
		COLOR_END
	);
}

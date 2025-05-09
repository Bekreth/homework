#include "intent_error.h"

IntentError bad_argument_count() {
	IntentError output = {
		.error_code = 1,
		.error_message = "Recieved the wrong number of arguments"
	};
	return output;
}

IntentError unrecognized_command() {
	IntentError output = {
		.error_code = 2,
		.error_message = "Unrecognized command"
	};
	return output;
}

IntentError invalid_motor_speed() {
	IntentError output = {
		.error_code = 4,
		.error_message = "Invalid motor speed provided"
	};
	return output;
}

IntentError invalid_numeric_input() {
	IntentError output = {
		.error_code = 5,
		.error_message = "Invalid numeric input"
	};
	return output;
}

IntentError out_of_range() {
	IntentError output = {
		.error_code = 6,
		.error_message = "Location of move is out of range"
	};
	return output;
}

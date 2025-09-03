#ifndef INTENT_ERROR_H
#define INTENT_ERROR_H

typedef struct IntentError {
	int error_code;
	char* error_message;
} IntentError;

IntentError unrecognized_command();
IntentError bad_argument_count();
IntentError invalid_motor_speed();
IntentError invalid_numeric_input();
IntentError out_of_range();

#endif

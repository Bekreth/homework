#ifndef INTENT_PARSER_H
#define INTENT_PARSER_H

#include "network.h"
#include "tokens.h"


typedef struct IntentError {
	int error_code;
	char* error_message;
} IntentError;

typedef union Intent {
	IntentError error;
	Commands commands;
} Intent;

Intent parse_tokens(Tokens*);

#endif

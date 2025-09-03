#ifndef INTENT_PARSER_H
#define INTENT_PARSER_H

#include "kinematics.h"
#include "network.h"
#include "tokens.h"
#include "intent_error.h"


typedef struct Intent {
	IntentError error;
	Commands commands;
} Intent;

Intent parse_tokens(Tokens*, Handedness);
Intent new_intent();

#endif

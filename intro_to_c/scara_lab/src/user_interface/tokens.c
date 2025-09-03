#include "tokens.h"

void expand_tokens(Tokens*);

Tokens new_tokens() {
	Tokens output = {
		.length = 0,
		.capacity = 5,
		.tokens = malloc(sizeof(char*) * 5)
	};
	return output;
}

void add_token(Tokens* tokens, char* new_token) {
	if (tokens->length == tokens->capacity) {
		expand_tokens(tokens);
	}
	tokens->tokens[tokens->length] = new_token;
	tokens->length += 1;
}

void expand_tokens(Tokens* tokens) {
	tokens->capacity += 5;
	tokens->tokens = realloc(tokens->tokens, sizeof(char*) * tokens->capacity);
}

void free_tokens(Tokens* tokens) {
	for (int i = 0; i < tokens->length; i++) {
		free(tokens->tokens[i]);
	}
	free(tokens->tokens);
	free(tokens);
}


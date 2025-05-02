#ifndef TOKENS_H
#define TOKENS_H

typedef struct Tokens {
	int length;
	int capacity;
	char** tokens;
} Tokens;

Tokens new_tokens();
void add_token(Tokens* , char*);
void free_token(Tokens*);

#endif

#include <stdio.h>
#include <stdlib.h>

#include "fibonacci.h"

void fibonacci(int iterations) {
	char** star_counter[iterations];
	star_counter[iterations] = malloc(iterations * sizeof(char*));
	int previous = 0;
	int output = 0;
	int next_step = 1;
	for (int i = 0; i <= iterations; i++) {
		if (i == iterations) {
			printf("%d", output);
		} else {
			printf("%d,", output);
		}
		star_counter[i] = malloc(sizeof(char) * output);
		for (int j = 0; j < output; j++) {
			star_counter[i][j]= '*';
		}
		previous = output;
		output += next_step;
		next_step = previous;
	}

	for (int i = 0; i <= iterations; i++) {
		printf("%s\n", star_counter[i]);
		free(star_counter[i]);
	}
	free(star_counter);
}

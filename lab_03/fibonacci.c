#include <stdio.h>
#include <stdlib.h>

#include "fibonacci.h"

void fibonacci(int iterations) {
	char** star_counter;
	star_counter = (char**)malloc((iterations-1) * sizeof(char*));
	int previous = 0;
	int output = 0;
	int next_step = 1;
	for (int i = 0; i < iterations; i++) {
		if (i == iterations) {
			printf("%d", output);
		} else {
			printf("%d,", output);
		}
		if (i !=0) {
			star_counter[i-1] = (char*)malloc(output * sizeof(char));
			for (int j = 0; j < output; j++) {
				star_counter[i-1][j]= '*';
			}
		}
		previous = output;
		output += next_step;
		next_step = previous;
	}
	printf("\n\n");
	for (int i = 0; i < iterations-1; i++) {
		printf("%s\n", star_counter[i]);
		// TODO: Sort out WTF is happening here
		//free(star_counter[i]);
	}
	free(star_counter);
}

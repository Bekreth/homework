#include <stdlib.h>

#include "die.h"


Die new_die(unsigned int sides) {
	Die output = {
		.sides = sides,
		.previous_roll = 0
	};
	return output;
}

unsigned int roll(Die* die) {
	die->previous_roll = (rand() % die->sides) + 1;
}

unsigned int total(Die** dice, int dice_count) {
	int running_total = 0;
	for (int i = 0; i < dice_count; i++) {
		running_total += dice[i]->previous_roll;
	}
	return running_total;
}

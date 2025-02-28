#include <stdio.h>
#include "tui.h"
#include "factorize.h"
#include "counter.h"

ScreenView build_factorize_view();

void run_factorize(Cache* cache) {
	ScreenView screen_view = build_factorize_view();
	while (1) {
		draw_screen_view(screen_view);
	}
}

PrimeFactors factorize(Cache* cache, unsigned long number) {
	PrimeCount list_of_primes = count_primes(cache, 2, number);

	int factor_count = 0;
	int list_capacity = list_of_primes.length * 2;
	unsigned long* factor_list = malloc(sizeof(unsigned long) * list_capacity);

	unsigned long quotient = number;
	for(int i = 0; i < list_of_primes.length; i++) {
		if (factor_count == list_capacity) {
			list_capacity *= 2;
			factor_list = realloc(factor_list, sizeof(unsigned long) * list_capacity);
		}
		unsigned long prime = list_of_primes.primes[i];
		if (quotient % prime == 0) {
			quotient = (unsigned long)(quotient / prime);
			factor_list[factor_count] = prime;
			factor_count++;
			if (quotient == 1) {
				break;
			}
			if (quotient % prime == 0) {
				i--;
			}
		}
	}

	factor_list = realloc(factor_list, sizeof(unsigned long) * factor_count);

	PrimeFactors output;
	output.length = factor_count;
	output.factors = factor_list;
	return output;	
}

ScreenView build_factorize_view() {
	ScreenView output;
	ScreenLine header_line = {
		.line = "Welcome to Prime Factorizer! To find the prime factors of various functions, provide input (x,y)! 0 to exit",
		.line_length = 106,
	};
	output.header = header_line;

	//TODO: original content

	ScreenLine user_input = {
		.line = " Please enter range x,y: ",
		.line_length = 20,
	};
	output.user_input_prompt = user_input;
	return output;
}

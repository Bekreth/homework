#include <stdio.h>

#include "tui.h"
#include "table.h"
#include "factorize.h"
#include "counter.h"

ScreenView build_factorize_view();

void run_factorize(Cache* cache) {
	ScreenView screen_view = build_factorize_view();
	while (1) {
		draw_screen_view(screen_view);
		unsigned long user_input_1 = 0;
		unsigned long user_input_2 = 0;
		char input[20];
		fgets(input, 20, stdin);
		sscanf(input, "%ld,%ld", &user_input_1, &user_input_2);
		if (user_input_1 == 0) {
			break;
		}

		screen_view.user_input_prompt.line = FACTOR_COUNT;
		draw_screen_view(screen_view);
		int factor_count = 100;
		fgets(input, 20, stdin);
		sscanf(input, "%d", &factor_count);

		screen_view.user_input_prompt.line = USER_VIEW_PROMPT;
		draw_screen_view(screen_view);
		char show_primes = 'n';
		fgets(input, 20, stdin);
		sscanf(input, "%c", &show_primes);

		char* starting_line = malloc(sizeof(char) * LINE_LENGTH);
		sprintf(
			starting_line,
			COUNTER_OUTPUT_TEMPLATE_FIRST_LINE_WITHOUT_PRIME,
			user_input_1,
			user_input_2,
			LINE_LENGTH
		);
		expand_content(&screen_view, starting_line, LINE_LENGTH);
		expand_content(&screen_view, MID_LINE, LINE_LENGTH);
		int condition_counter = 0;
		for (unsigned long i = user_input_1; i < user_input_2; i++) {
			PrimeFactors factors = factorize(cache, i);
			printf("%d %d\n", i, factors.length);
			if (factors.length != factor_count) {
				continue;
			}
			condition_counter++;

			if (show_primes == 'y') {
				for (int j = 0; j < factors.length; j++) {
					char* line = malloc(sizeof(char) * LINE_LENGTH);
					if (j == 0) {
						sprintf(
							line,
							FACTOR_OUTPUT_TEMPLATE_FIRST_LINE,
							i,
							factors.factors[j],
							LINE_LENGTH
						);
					} else if (j < factors.length) {
						sprintf(
							line,
							COUNTER_OUTPUT_TEMPLATE_PRIME,
							factors.factors[j],
							LINE_LENGTH
						);
					} else {
						sprintf(
							line,
							COUNTER_OUTPUT_TEMPLATE_LAST_LINE,
							factors.factors,
							LINE_LENGTH
						);
					}
					expand_content(&screen_view, line, LINE_LENGTH);
				}
			} else {
				char* first_line = malloc(sizeof(char) * LINE_LENGTH);
				sprintf(
					first_line,
					FACTOR_OUTPUT_TEMPLATE_FIRST_LINE_WITHOUT_PRIME,
					i,
					LINE_LENGTH
				);
				expand_content(&screen_view, first_line, LINE_LENGTH);
				char* second_line = malloc(sizeof(char) * LINE_LENGTH);
				sprintf(
					second_line,
					COUNTER_OUTPUT_TEMPLATE_LAST_LINE,
					factors.length,
					LINE_LENGTH
				);
				expand_content(&screen_view, second_line, LINE_LENGTH);
			}
			expand_content(&screen_view, MID_LINE, LINE_LENGTH);
		}
		char* ending_line = malloc(sizeof(char) * LINE_LENGTH);
		sprintf(
			ending_line,
			COUNTER_OUTPUT_TEMPLATE_LAST_LINE,
			condition_counter,
			LINE_LENGTH
		);
		expand_content(&screen_view, ending_line, LINE_LENGTH);
		expand_content(&screen_view, LINE_DRAWING, LINE_LENGTH);
		screen_view.user_input_prompt.line = USER_RANGE_PROMPT;
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

	output.content_length = 2;
	output.content = malloc(sizeof(ScreenView) * output.content_length);
	ScreenLine line_0 = {
		.line = LINE_DRAWING,
		.line_length = LINE_LENGTH,
	};
	output.content[0] = line_0;

	ScreenLine line_1 = {
		.line = OUTPUT_HEADER,
		.line_length = LINE_LENGTH,
	};
	output.content[1] = line_1;

	ScreenLine user_input = {
		.line = " Please enter range x,y: ",
		.line_length = LINE_LENGTH,
	};
	output.user_input_prompt = user_input;
	return output;
}

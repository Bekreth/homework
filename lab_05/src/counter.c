#include <stdio.h>

#include "tui.h"
#include "counter.h"

ScreenView build_counter_view();

const char* LINE_DRAWING = "--------------------------";
const int LINE_LENGTH = 25;
const char* USER_RANGE_PROMPT = "|User Range? |Primes      |";
const char* USER_VIEW_PROMPT  = "|Display results? (y/n)   |";


void run_counter(Cache* cache) {
	ScreenView screen_view = build_counter_view();
	while (1) {
		draw_screen_view(screen_view);
		unsigned long user_input_1 = 0;
		unsigned long user_input_2 = 0;
		scanf("%ld,%ld", &user_input_1, &user_input_2);
		if (user_input_1 == 0) {
			break;
		}

		PrimeCount prime_count = count_primes(cache, user_input_1, user_input_2);
		//TODO
		//screen_view.user_input.line = USER_VIEW_PROMPT;
		ScreenView screen_view = build_counter_view();
		char view_results = "a";
		scanf("%c", &view_results);

		if (view_results == "y") {
			//TODO: expand content with prime list
		}
		//TODO: expand content with prime count and line
	}
}

PrimeCount count_primes(Cache* cache, unsigned long number_1, unsigned long number_2) {
	if (cache->prime_cache->largest_known_prime < number_2) {
		saturate_prime_cache(cache, number_2);
	}

	int first = index_of_first_following_prime(cache->prime_cache, number_1);
	int last = index_of_previous_preceding_prime(cache->prime_cache, number_2);
	PrimeCount output;
	output.length = (last - first) + 1;
	output.primes = malloc(sizeof(int) * output.length);

	for (int i = first; i <= last; i++) {
		output.primes[i - first] = cache->prime_cache->known_primes[i];
	}

	return output;
}

void saturate_prime_cache(Cache* cache, unsigned long number) {
	for (int i = cache->prime_cache->largest_known_prime; i <= number; i++) {
		is_prime(cache, i);
	}
}

int index_of_first_following_prime(PrimeCache* cache, unsigned long number) {
	for (int i = 0; i < cache->length; i++) {
		if (cache->known_primes[i] >= number) {
			return i;
		}
	}
}

int index_of_previous_preceding_prime(PrimeCache* cache, unsigned long number) {
	for (int i = cache->length - 1; i >= 0; i--) {
		if (cache->known_primes[i] <= number) {
			return i;
		}
	}
}

ScreenView build_counter_view() {
	ScreenView output;
	ScreenLine header_line = {
		.line = "Welcome to Prime Counter! Enter a range of numbers (x,y) to find out how many primes are between them! 0 to exit",
		.line_length = 111,
	};
	output.header = header_line;

	/*
	output.content_length = 2;
	output.content = malloc(sizeof(ScreenView) * output.content_length);
	ScreenLine line_0 = {
		.line = LINE_DRAWING,
		.line_length = LINE_LENGTH,
	};
	output.content[0] = line_0;

	ScreenLine line_1 = {
		.line = USER_RANGE_PROMPT,
		.line_length = 25,
	};
	output.content[1] = line_1;

	ScreenLine user_input = {
		.line = " Please enter range x,y: ",
		.line_length = 20,
	};
	output.user_input_prompt = user_input;
	*/
	return output;
}

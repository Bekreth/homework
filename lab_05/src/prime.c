#include <stdlib.h>
#include <math.h>

#include "tui.h"
#include "prime.h"

const char* PRIME_TEMPLATE = "|%-10s|%-10d|";

bool number_is_known_prime(PrimeCache*, unsigned long );
bool number_is_known_composite(CompositeCache*, unsigned long );
bool divisible_by_known_primes(PrimeCache*, unsigned long);

ScreenView build_prime_view();

void run_prime(Cache* cache) {
	ScreenView screen_view = build_prime_view();
	while (1) {
		draw_screen_view(screen_view);
		unsigned long user_input = 0;
		scanf("%ld", &user_input);
		if (user_input == 0) {
			break;
		}

		int prime_output_length = 64;
		char* prime_output_value = malloc(sizeof(char) * prime_output_length);
		sprintf(
			prime_output_value,
			PRIME_TEMPLATE,
			is_prime(cache, user_input) ? "Prime" : "Composite",
			user_input
		);
		expand_content(&screen_view, prime_output_value, prime_output_length);
	}
}

bool is_prime(Cache* cache, unsigned long number) {
	if (number_is_known_prime(cache->prime_cache, number)) {
		return true;
	}
	if (number_is_known_composite(cache->composite_cache, number)) {
		return false;
	}
	if (divisible_by_known_primes(cache->prime_cache, number)) {
		return false;
	}

	for (int i = cache->prime_cache->largest_known_prime + 1; i < number; i++) {
		if (divisible_by_known_primes(cache->prime_cache, i)) {
			append_composite_cache(cache->composite_cache, i);
		} else {
			append_prime_cache(cache->prime_cache, i);
			if (number % i == 0) {
				return false;
			}
		}
	}

	append_prime_cache(cache->prime_cache, number);
	return true;
}

bool number_is_known_prime(PrimeCache* cache, unsigned long number) {
	if (number > cache->largest_known_prime) {
		return false;
	}
	for (int i = 0; i < cache->length; i++) {
		if (number == cache->known_primes[i]) {
			return true;
		}
	}
	return false;
}


bool number_is_known_composite(CompositeCache* cache, unsigned long number) {
	if (number > cache->largest_known_composite) {
		return false;
	}
	for (int i = 0; i < cache->length; i++) {
		if (number == cache->known_composites[i]) {
			return true;
		}
	}
	return false;
}

bool divisible_by_known_primes(PrimeCache* cache, unsigned long number) {
	for (int i = 0; i < cache->length; i++) {
		unsigned long known_prime = cache->known_primes[i];
		if (number == known_prime) {
			return false;
		}
		if (number % known_prime == 0) {
			return true;
		}
	}
	return false;
}

ScreenView build_prime_view() {
	ScreenView output;
	ScreenLine header_line = {
		.line = "Welcome to Prime! Input a number to find out if its prime. 0 to exit",
		.line_length = 67,
	};
	output.header = header_line;

	output.content_length = 2;
	output.content = malloc(sizeof(ScreenView) * output.content_length);

	ScreenLine line_0 = {
		.line = "-----------------------",
		.line_length = 23,
	};
	output.content[0] = line_0;

	ScreenLine line_1 = {
		.line = "|Prime?    |User value|",
		.line_length = 23,
	};
	output.content[1] = line_1;

	ScreenLine user_input = {
		.line = " Enter value please: ",
		.line_length = 20,
	};
	output.user_input_prompt = user_input;

	return output;
}

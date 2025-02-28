#include <stdio.h>

#include "counter.h"

void run_counter(Cache* cache) {
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

#include <stdio.h>

#include "counter.h"

void run_counter(Cache* cache) {
}

void count_primes(Cache* cache, unsigned long number_1, unsigned long number_2) {
	if (cache->prime_cache->largest_known_prime < number_2) {
		// Prime the cache
		is_prime(cache, number_2);
	}

	int i1 = index_of_first_following_prime(cache->prime_cache, number_1);
	int i2 = index_of_previous_preceding_prime(cache->prime_cache, number_2);
	int number_of_primes = i2 - i1;
		


	// TODO: the "exit fast" approach doesn't work great on this.  Need to saturate the 
	//       queue before running the count
	printf("Space between is %d: %d, %d", number_of_primes, i1, i2);

}

int index_of_first_following_prime(PrimeCache* cache, unsigned long number) {
	for (int i = 0; i < cache->length; i++) {
		if (cache->known_primes[i] > number) {
			return i;
		}
	}
}

int index_of_previous_preceding_prime(PrimeCache* cache, unsigned long number) {
	for (int i = cache->length - 1; i >= 0; i--) {
		if (cache->known_primes[i] < number) {
			return i;
		}
	}
}

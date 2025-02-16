#include <stdlib.h>
#include <math.h>

#include "prime.h"

bool number_is_known_composite(CompositeCache*, unsigned long );
bool divisible_by_known_primes(PrimeCache*, unsigned long);

bool is_prime(Cache* cache, unsigned long number) {
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


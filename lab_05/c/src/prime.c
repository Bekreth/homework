#include <stdlib.h>
#include <math.h>

#include "prime.h"

void append_prime_cache(PrimeCache*, unsigned long);
void append_composite_cache(CompositeCache*, unsigned long);

bool number_is_known_composite(CompositeCache*, unsigned long );
bool divisible_by_known_primes(PrimeCache*, unsigned long);

Cache new_cache() {
	CompositeCache* composite_cache = malloc(sizeof(CompositeCache));
	composite_cache->capacity = 10;
	composite_cache->length = 0;
	composite_cache->known_composites = malloc(sizeof(unsigned long) * 10);
	composite_cache->largest_known_composite = 0;

	PrimeCache* prime_cache = malloc(sizeof(PrimeCache));
	prime_cache->capacity = 10;
	prime_cache->length = 0;
	prime_cache->known_primes = malloc(sizeof(unsigned long) * 10);
	prime_cache->largest_known_prime = 0;

	Cache output = {
		.prime_cache = prime_cache,
		.composite_cache = composite_cache
	};

	append_prime_cache(prime_cache, 2);
	append_composite_cache(composite_cache, 4);

	return output;
}

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

void append_prime_cache(PrimeCache* cache, unsigned long number) {
	if (cache->capacity == cache->length) {
		cache->known_primes = realloc(
			cache->known_primes, 
			sizeof(unsigned long) * (2 * cache->length)
		);
		cache->capacity *= 2;
	}
	cache->known_primes[cache->length] = number;
	cache->length += 1;
	cache->largest_known_prime = number;
}

void append_composite_cache(CompositeCache* cache, unsigned long number) {
	if (cache->capacity == cache->length) {
		cache->known_composites = realloc(
			cache->known_composites, 
			sizeof(unsigned long) * (2 * cache->length)
		);
		cache->capacity *= 2;
	}
	cache->known_composites[cache->length] = number;
	cache->length += 1;
	cache->largest_known_composite = number;
}

#include <stdlib.h>

#include "cache.h"

void append_prime_cache(PrimeCache*, unsigned long);
void append_composite_cache(CompositeCache*, unsigned long);

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

#ifndef PRIME_H
#define PRIME_H

#include <stdbool.h>

// These two caches are begging for polymorphic behavior.  Will refrain for readability
typedef struct CompositeCache {
	int capacity;
	int length;
	unsigned long* known_composites;
	unsigned long largest_known_composite;
} CompositeCache;

typedef struct PrimeCache {
	int capacity;
	int length;
	unsigned long* known_primes;
	unsigned long largest_known_prime;
} PrimeCache;

typedef struct Cache {
	CompositeCache* composite_cache;
	PrimeCache* prime_cache;
} Cache;

Cache new_cache();
bool is_prime(Cache*, unsigned long);

#endif


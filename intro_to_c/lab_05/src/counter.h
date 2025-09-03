#ifndef COUNTER_H
#define COUNTER_H

#include "cache/cache.h"

typedef struct PrimeCount {
	int* primes;
	int length;
} PrimeCount;

void run_counter(Cache*);
PrimeCount count_primes(Cache*, unsigned long, unsigned long);

#endif

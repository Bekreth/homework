#ifndef FACTORIZE_H
#define FACTORIZE_H

#include "cache/cache.h"

typedef struct PrimeFactors {
	unsigned long* factors;
	int length;
} PrimeFactors;

void run_factorize(Cache*);
PrimeFactors factorize(Cache*, unsigned long);

#endif


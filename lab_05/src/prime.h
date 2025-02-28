#ifndef PRIME_H
#define PRIME_H

#include <stdbool.h>

#include "cache/cache.h"

void run_prime(Cache*);
bool is_prime(Cache*, unsigned long);

#endif


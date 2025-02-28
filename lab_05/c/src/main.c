#include <stdio.h>

#include "prime.h"
#include "counter.h"
#include "factorize.h"
#include "cache/cache.h"

int main() {
	Cache cache = new_cache();
	while (1) {
		unsigned long number = 0;
		printf("Enter a number: ");
		scanf("%ld", &number);
		if (number == 0) {
			break;
		}
		if (is_prime(&cache, number)) {
			printf("\nPRIME\n");
		} else {
			printf("\nCOMPOSITE\n");
		}
	}
}

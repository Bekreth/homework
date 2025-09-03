#include <stdio.h>

#define N 5

// WARNING: Factorials get large very fast.  A single unsigned long is being used
// to store the value of the long and thus the value of the factorial
// cannot exceed 18446744073709551615. The maximum value of N is 20

int main(int argc, char *argv[]) {
	unsigned long output = 1;
	for (int i = N; i > 0; i--) {
		output *= i;
	}
	printf("%ld\n", output);
	return 0;
}

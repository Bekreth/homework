#include "sorter.h"

void sort_array_sums(int* x_array, int* y_array, int length) {
	int* sums = malloc(sizeof(int) * length);

	for (int i = 0; i < length; i++) {
		sums[i] = x_array[i] + y_array[i];
	}

	int intermediate;
	for (int i = 0; i < length - 1; i++) {
		for (int j = i+1; j < length; j++) {
			if (sums[i] > sums[j]) {
				intermediate = sums[i];
				sums[i] = sums[j];
				sums[j] = intermediate;

				intermediate = x_array[i];
				x_array[i] = x_array[j];
				x_array[j] = intermediate;

				intermediate = y_array[i];
				y_array[i] = y_array[j];
				y_array[j] = intermediate;
			}
		}
	}

	free(sums);
}

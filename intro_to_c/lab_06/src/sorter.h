#ifndef SORTER_H
#define SORTER_H

// sort_array_sums takes in two arrays.  It then sorts each array such that the sum of the same indicies are
// arranged from least value to most value.  This is a bubble sort, don't expect much.  Also, this has no
// output and overwrite data in place.  This is not mutex friendly. Additionally, there are no safety rails,
// the data you submit must already be clean and in appropriate format. You've been warned.
void sort_array_sums(int*, int*, int);

#endif

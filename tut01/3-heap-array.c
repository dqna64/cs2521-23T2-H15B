#include <stdio.h>
#include <stdlib.h>

/**
 * If you want to initialise an array with unknown size
 * (e.g. size given by user via stdin), then the array must be
 * allocated on the heap i.e. dynamic array, size can change in run-time.
 *
 */

int main(void) {

  int size;
  scanf("%d", &size);

  int *a = malloc(sizeof(int) * size);
  // int b[size] = {2,5,7}; // can't initialise stack memory with unknown size

  for (int i = 0; i < size; i++) {
    a[i] = i;
  }
}
#include <stdlib.h>
/**
 * Initial
 *
 */
int stackArray(void) {
  int a[5];
  for (int i = 0; i < 5; i++) {
    a[i] = 42;
  }
}

/**
 * Solution
 *
 */
int heapArray(void) {
  int *a = malloc(5 * sizeof(int));
  for (int i = 0; i < 5; i++) {
    a[i] = 42;
  }
}

int main(void) {
  stackArray();
  heapArray();
  return 0;
}
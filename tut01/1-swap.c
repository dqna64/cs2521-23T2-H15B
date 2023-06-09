#include <stdio.h>

void swapIncorrectly(int a, int b) {
  int tmp = a;
  a = b;
  b = tmp;
}

void swapCorrectly(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

int main(void) {
  int a = 5;
  int b = 7;

  printf("=== Incorrect ===\n");
  printf("Before swap: a = %d, b = %d\n", a, b);
  swapIncorrectly(a, b);
  printf("After swap: a = %d, b = %d\n", a, b);

  printf("=== Correct ===\n");
  printf("Before swap: a = %d, b = %d\n", a, b);
  swapCorrectly(&a, &b);
  printf("After swap: a = %d, b = %d\n", a, b);
}

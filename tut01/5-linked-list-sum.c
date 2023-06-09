#include <stdio.h>
#include <stdlib.h>

struct node {
  int value;
  struct node *next;
};

int main(void) {
  struct node *n1 = malloc(sizeof(*n1));
  struct node *n2 = malloc(sizeof(*n2));
  struct node *n3 = malloc(sizeof(*n3));

  n1->value = 1;
  n1->next = n2;

  n2->value = 2;
  n2->next = n3;

  n3->value = 3;
  n3->next = NULL;

  // While loop
  int sum1 = 0;
  struct node *curr = n1;
  while (curr != NULL) {
    sum1 += curr->value;
    curr = curr->next;
  }
  printf("sum1: %d\n", sum1);

  // For loop
  int sum2 = 0;
  for (struct node *curr = n1; curr != NULL; curr = curr->next) {
    sum2 += curr->value;
  }
  printf("sum2: %d\n", sum2);
}
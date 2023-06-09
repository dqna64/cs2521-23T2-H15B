#include <stdlib.h>

struct node {
  int value;
  struct node *next;
};

int main(void) {
  // struct node n;  // {value: 5, next: 0x48320}
  struct node *n = malloc(sizeof(struct node)); //  0x473820
  n->value = 42;
  n->next = NULL;

  // do smthn with the node

  free(n);

  return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct node {
  int value;
  struct node *next;
};

struct list {
  struct node *head;
};

int listLengthIterative(struct node *l) {
  int length = 0;
  while (l != NULL) {
    length += 1;
    l = l->next;
  }
  return length;
}

int listLengthRecursive(struct node *l) {
  // Base case:
  if (l == NULL) {
    return 0;
  }

  return 1 + listLengthRecursive(l->next); // 1 + length (2 -> 3 -> 4 -> X)
}

int main(void) {
  struct node *node1 = malloc(sizeof(struct node));
  struct node *node2 = malloc(sizeof(struct node));
  struct node *node3 = malloc(sizeof(struct node));
  struct node *node4 = malloc(sizeof(struct node));
  node1->value = 1;
  node1->next = node2;
  node2->value = 2;
  node2->next = node3;
  node3->value = 3;
  node3->next = node4;
  node4->value = 4;
  node4->next = NULL;

  // 1 -> 2 -> 3 -> 4 -> X

  printf("listLength: %d\n", listLengthRecursive(node1));
}

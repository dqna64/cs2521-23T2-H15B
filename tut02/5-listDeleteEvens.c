#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct node {
  int value;
  struct node *next;
};

struct list {
  struct node *head;
};

struct node *listDeleteEvensIterative(struct node *l) {
  struct node *prev = NULL;
  struct node *curr = l;
  while (curr != NULL) {
    if (curr->value % 2 == 0) {
      if (prev) {
        struct node *temp = curr;
        prev->next = curr->next;
        // prev stays the same
        curr = curr->next;
        free(temp);
      } else {
        // Remove head
        struct node *temp = curr;
        l = curr->next;
        // prev stays NULL
        curr = curr->next;
        free(temp);
      }
    } else {
      prev = curr;
      curr = curr->next;
    }
  }
  return l;
}

struct node *listDeleteEvensRecursive(struct node *l) {
  // Base case(s):
  if (l == NULL) {
    return NULL;
  }

  if (l->value % 2 == 0) { // If this node is even
    struct node *nextNode = l->next;
    free(l); // Delete this even node
    return listDeleteEvensRecursive(nextNode);
  }
  l->next = listDeleteEvensRecursive(l->next);
  return l;
}

/**
 * If we make use of struct list, which wraps around the first node,
 * then we also need to make a function listDeleteEvens(struct list*) to wrap
 * around our recursive function listDeleteEvensRecursive(struct node*)
 *
 */
void listDeleteEvens(struct list *l) {
  l->head = listDeleteEvensRecursive(l->head);
}

/**
 * Helper function to print a linked list.
 * For example:
 *    1 -> 2 -> 3 -> 4 -> X
 *
 * @param l
 */
void printList(struct node *l) {
  if (l == NULL) {
    printf("X\n");
    return;
  }
  printf("%d -> ", l->value);
  printList(l->next);
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

  printf("linked list before listDeleteEvens: ");
  printList(node1); // 1 -> 2 -> 3 -> 4 -> X

  node1 = listDeleteEvensRecursive(node1);

  printf("linked list after listDeleteEvens: ");
  printList(node1); // 1 -> 3 -> X
}
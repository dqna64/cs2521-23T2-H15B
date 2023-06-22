#include <stdio.h>
#include <stdlib.h>

/**
 * Run command:
 *    $ gcc 4.c && ./a.out
 *
 */

struct node {
  int value;
  struct node *left;
  struct node *right;
};

int bstCountOdds(struct node *t) {
  if (t == NULL) {
    return 0;
  } else if (t->value % 2 != 0) {
    return 1 + bstCountOdds(t->left) + bstCountOdds(t->right);
  } else {
    return bstCountOdds(t->left) + bstCountOdds(t->right);
  }
}

int main(void) {
  struct node *node1 = malloc(sizeof(struct node));
  struct node *node2 = malloc(sizeof(struct node));
  struct node *node3 = malloc(sizeof(struct node));
  struct node *node4 = malloc(sizeof(struct node));

  node1->value = 5;
  node2->value = 2;
  node3->value = 8;
  node4->value = 7;

  node1->left = node2;
  node1->right = node3;
  node2->left = NULL;
  node2->right = NULL;
  node3->left = node4;
  node3->right = NULL;
  node4->left = NULL;
  node4->right = NULL;

  int result = bstCountOdds(node1);
  printf("Number of odd nodes in BST: %d\n", result); // should be 2
}
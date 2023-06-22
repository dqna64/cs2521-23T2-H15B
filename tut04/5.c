#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Run command:
 *    $ gcc 5.c bst.c && ./a.out
 *
 */

int bstHeight(struct node *t) {
  if (t == NULL) {
    return -1;
  }

  int lh = bstHeight(t->left);
  int rh = bstHeight(t->right);
  if (lh > rh) {
    return lh + 1;
  } else {
    return rh + 1;
  }
}

int main(void) {

  struct node *tree = NULL;
  tree = insert(tree, 5);
  tree = insert(tree, 6);
  tree = insert(tree, 2);
  tree = insert(tree, 3);
  tree = insert(tree, 4);
  tree = insert(tree, 7);
  tree = insert(tree, 1);

  int result = bstHeight(tree);
  printf("Height of BST: %d\n", result); // should be 3
}
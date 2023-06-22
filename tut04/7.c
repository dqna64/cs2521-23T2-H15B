#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Run command:
 *    $ gcc 7.c bst.c && ./a.out
 *
 */

int bstNodeLevel(struct node *t, int key) {
  // Reached bottom of path through tree and did not find key in the path.
  if (t == NULL) {
    return -1;
  }

  // If found key in tree
  if (t->value == key) {
    return 0;
  }

  int level;
  if (key < t->value) {
    level = bstNodeLevel(t->left, key);
  } else { // key > t->value
    level = bstNodeLevel(t->right, key);
  }

  // -1 OR 0..
  if (level == -1) {
    // If key was not found:
    return -1;
  } else {
    // Otherwise key was found, increment level
    return level + 1;
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

  int result = bstNodeLevel(tree, 3);
  printf("level of 3: %d\n", result); // should be 2

  int result2 = bstNodeLevel(tree, 9);
  printf("level of 9: %d\n", result2); // should be -1
}
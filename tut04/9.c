#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Run command:
 *    $ gcc 9.c bst.c && ./a.out
 *
 */

#define NOT_HEIGHT_BALANCED -99

int isHeightBalanced(struct node *t) {
  if (t == NULL) {
    return -1;
  }

  // First determine height of left and right subtrees.
  int lh = isHeightBalanced(t->left);  // height of left subtree
  int rh = isHeightBalanced(t->right); // height of right subtree

  // If either subtree is unbalanced, then this node is also unbalanced.
  if (lh == NOT_HEIGHT_BALANCED || rh == NOT_HEIGHT_BALANCED) {
    return NOT_HEIGHT_BALANCED;
  }

  if (abs(lh - rh) <= 1) {
    int height;
    if (lh > rh) {
      height = lh;
    } else {
      height = rh;
    }
    return height + 1;
  } else {
    return NOT_HEIGHT_BALANCED;
  }
}

int main(void) {

  struct node *tree1 = NULL;
  tree1 = insert(tree1, 5);
  tree1 = insert(tree1, 2);
  tree1 = insert(tree1, 1);
  tree1 = insert(tree1, 8);
  tree1 = insert(tree1, 7);

  int result = isHeightBalanced(tree1);
  printf("is balanced?: %d\n", result);
  // should be yes, balanced, so returns height of tree which is 2

  struct node *tree2 = NULL;
  tree2 = insert(tree2, 5);
  tree2 = insert(tree2, 2);
  tree2 = insert(tree2, 1);
  tree2 = insert(tree2, 0);
  tree2 = insert(tree2, 8);
  tree2 = insert(tree2, 7);
  tree2 = insert(tree2, 6);
  int result2 = isHeightBalanced(tree2);
  printf("is balanced?: %d\n", result2);
  // should be no, not balanced, so returns NOT_HEIGHT_BALANCED (-99)
}
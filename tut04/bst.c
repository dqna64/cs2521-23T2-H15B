#include "bst.h"
#include <stdlib.h>

struct node *insert(struct node *root, int x) {
  if (root == NULL) {
    root = malloc(sizeof(struct node));
    root->value = x;
    root->left = root->right = NULL;
  } else if (x < root->value)
    root->left = insert(root->left, x);
  else if (x > root->value)
    root->right = insert(root->right, x);
  return root;
}
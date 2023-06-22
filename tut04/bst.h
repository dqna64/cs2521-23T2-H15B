struct node {
  int value;
  struct node *left;
  struct node *right;
};

struct node *insert(struct node *root, int value);
#include <stdlib.h>

struct node {
  int value;
  struct node *next;
};

struct list {
  struct node *head; // 0x4328   OR   NULL
};

int listLength(struct list *list);

/**
 * Takes in a struct node*
 * To insert at head, you need to return the new head node.
 */
struct node *insertNodeAtHead(struct node *head, int num) {
  struct node *newHead = malloc(sizeof(struct node));
  newHead->value = num;
  newHead->next = head;
  return newHead;
}

/**
 * Takes in a struct list*
 * To insert at head, you just change the `struct node* head` field of the
 *`struct list *list`
 */
void insertNodeAtHead2(struct list *list, int num) {
  struct node *newHead = malloc(sizeof(struct node));
  newHead->value = num;
  newHead->next = list->head;
  list->head = newHead;
}

int main(void) {
  // Using insertNodeAtHead()
  struct node existingNode = {.value = 48392, .next = NULL};
  struct node *head = insertNodeAtHead(&existingNode, 3);

  // Using insertNodeAtHead2
  struct node *existingNode2 = malloc(sizeof(*existingNode2));
  struct list *myList;
  myList->head = existingNode2;
  insertNodeAtHead2(myList, 8);
}
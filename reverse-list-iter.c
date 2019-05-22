#include "rlist_iter.h"
#include <stdlib.h>
#include <assert.h>

//see rlist_iter.h for details
void reverse_iter(struct llist *list) {
  struct node *node = list->first;
  struct node *node1 = list->first;
  if (!node) return;
  if (!node->next) return;
  struct node *node2 = list->first->next;
  struct node *node3 = node2;
  while (node3) {
    node3 = node2->next;
    node2->next = node1;
    node1 = node2;
    node2 = node3;
  }
  node->next = NULL;
  list->first = node1;
}

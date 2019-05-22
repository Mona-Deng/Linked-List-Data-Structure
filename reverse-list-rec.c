#include "rlist_rec.h"
#include <stdlib.h>
#include <assert.h>

//reverse(list, prevnode): reverses the order of [list](i.e. 
//a wrapper function for reverse_rec(list)) and returns the 
//last node of the current list. The algorithm is recursive.
//requires: list and prevnode are not NULL
//effects: mutates [list]
//time: O(n), where n is the length of [list]
static struct node *reverse(struct llist *list, struct node *prevnode) {
  assert(list);
  assert(prevnode);
  struct node *node = list->first;
  if (!node) {
    list->first = prevnode;
    return prevnode;
  }
  list->first = node->next;
  struct node *curnode = reverse(list, node);
  curnode->next = prevnode;
  return prevnode;
}
  
//see rlist_rec.h for details
void reverse_rec(struct llist *list) {
  assert(list);
  struct node *node = list->first;
  if (!node) return;
  list->first = node->next;
  reverse(list, node);
  node->next = NULL;
 }




#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "llist.h"

/*
 * node_create(value) returns a new node with value set to [value].
 * effects: allocates heap memory (caller must free by calling node_destroy)
 * time:    O(1)
 */
struct node *node_create(int value) {
  struct node *new_node = malloc(sizeof(struct node));
  new_node->value = value;
  new_node->next = NULL;
  return new_node;
}

/*
 * node_destroy(node) frees the memory allocated by [node].
 * effects: deallocates [node]
 * time:    O(1)
 */
void node_destory(struct node* node) {
  assert(node);
  free(node);
}

struct llist *list_create(void) {
  struct llist *list = malloc(sizeof(struct llist));
  list->first = NULL;
  return list;
}

void list_destroy(struct llist *list) {
  assert(list);
  struct node *current = list->first;
  while (current != NULL) { // travers nodes
    struct node *to_free = current;
    current = current->next;
    node_destory(to_free);
  }
  free(list);
}

void list_append(struct llist *list, const int value) {
  assert(list);
  struct node *new_node = node_create(value);
  if (list->first == NULL) { // list is empty
    list->first = new_node;
  } else {
    struct node *current = list->first;
    while (current->next != NULL) { // find last node
      current = current->next;
    }
    current->next = new_node;
  }
}

void list_print(const struct llist *list) {
  assert(list);
  struct node *current = list->first;
  if (current == NULL) { // list is empty
    printf("List empty\n");
  } else {
    int i = 0;
    while(current != NULL) { // travers nodes
      printf("Node #%d: %d\n", i++, current->value);
      current = current->next;
    }
  }
}

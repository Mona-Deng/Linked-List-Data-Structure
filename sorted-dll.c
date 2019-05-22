#include <assert.h>
#include <stdio.h>
#include "sdll.h"
#include <stdlib.h>

// THERE IS NO NEED TO CHANGE THIS STRUCT
struct sllist {
  struct node *first;
  int length;
};

// THERE IS NO NEED TO CHANGE THIS STRUCT
struct node {
  struct node *next;
  struct node *prev;
  int value;
};

//see sdll.h for details
struct sllist *list_create(void) {
  struct sllist *list = malloc(sizeof(struct sllist));
  list->length = 0;
  list->first = NULL;
  return list;
}

//see sdll.h for details
void list_destroy(struct sllist *list) {
  assert(list);
  struct node *curnode = list->first;
  struct node *nextnode = NULL;
  while (curnode) {
    nextnode = curnode->next;
    free(curnode);
    curnode = nextnode;
  }
  free(list);
}

//see sdll.h for details
void list_insert(struct sllist *list, const int value) {
  assert(list);
  struct node *node = list->first;
  struct node *newnode = malloc(sizeof(struct node));
  list->length += 1;
  newnode->value = value;
  if (!node) {
    list->first = newnode;
    newnode->next = NULL;
    newnode->prev = NULL;
    return;
  }
  while (node->value <= value && node->next) {
    node = node->next;
  }
  if (node->value > value) {
    if (node->prev) node->prev->next = newnode;
    else list->first = newnode;
    newnode->prev = node->prev;
    node->prev = newnode;
    newnode->next = node;
    return;
  }
  node->next = newnode;
  newnode->prev = node;
  newnode->next = NULL;
}

//see sdll.h for details
bool list_remove(struct sllist *list, const int value) {
  assert(list);
  struct node *node = list->first;
  if (!node) return false;
  struct node *nextnode = list->first->next;
  if (node->value == value) {
    list->length -= 1;
    list->first = nextnode;
    if (list->first) list->first->prev = NULL;
    free(node);
    return true;
  }
  while (node->value <= value) {
    if (node->value == value) {
      list->length -= 1;
      node->prev->next = nextnode;
      if (nextnode) nextnode->prev = node->prev;
      free(node);
      return true;
    }
    node = node->next;
    if (!node) return false;
    nextnode = node->next;
  }
  return false;
}

// DO NOT MODIFY list_print(..)!
void list_print(const struct sllist *list) {
  assert(list);
  struct node *current = list->first;
  if (current == NULL) {
    printf("List empty\n");
  } else {
    int i = 0;
    while(current != NULL) {
      printf("Elem #%d/%d: %d\n", i++, list->length - 1, current->value);
      current = current->next;
    }
  }
}

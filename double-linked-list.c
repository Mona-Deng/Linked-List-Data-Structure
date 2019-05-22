#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include "dll.h"
#include <stdlib.h>

// THERE IS NO NEED TO CHANGE THIS STRUCT
struct llist {
  struct node *first;
  struct node *last;
  int length;
};

// THERE IS NO NEED TO CHANGE THIS STRUCT
struct node {
  struct node *next;
  struct node *prev;
  int value;
};

//see dll.h for details
struct llist *list_create(void) {
  struct llist *list = malloc(sizeof(struct llist));
  list->length = 0;
  list->first = NULL;
  list->last = NULL;
  return list;
}

//see dll.h for details
void list_destroy(struct llist *list) {
  assert(list);
  struct node *curnode = list->first;
  struct node *nextnode = NULL;
  while (curnode) {
    list->length -= 1;
    nextnode = curnode->next;
    free(curnode);
    curnode = nextnode;
  }
  free(list);
}

//see dll.h for details
void list_insert_front(struct llist *list, const int value) {
  assert(list);
  struct node *node = malloc(sizeof(struct node));
  list->length += 1;
  if (list->length == 1) {
    node->value = value;
    node->prev = NULL;
    node->next = NULL;
    list->first = node;
    list->last = node;
    return;
  }
  node->value = value;
  node->next = list->first;
  node->prev = NULL;
  list->first->prev = node;
  list->first = node;
}

//see dll.h for details
void list_insert_back(struct llist *list, const int value) {
  assert(list);
  struct node *node = malloc(sizeof(struct node));
  list->length += 1;
  if (list->length == 1) {
    node->value = value;
    node->prev = NULL;
    node->next = NULL;
    list->first = node;
    list->last = node;
    return;
  }
  node->value = value;
  node->next = NULL;
  node->prev = list->last;
  list->last->next = node;
  list->last = node;
}

//see dll.h for details
bool list_remove_front(struct llist *list, int *value) {
  assert(list);
  assert(value);
  if (list->length == 0) return false;
  *value = list->first->value;
  list->length -= 1;
  if (list->length == 0) {
    struct node *node = list->first;
    list->first = NULL;
    list->last = NULL;
    free(node);
    return true;
  }
  list->first = list->first->next;
  free(list->first->prev);
  list->first->prev = NULL;
  return true;
}


//see dll.h for details
bool list_remove_back(struct llist *list, int *value) {
  assert(list);
  assert(value);
  if (list->length == 0) return false;
  *value = list->last->value;
  list->length -= 1;
  if (list->length == 0) {
    struct node *node = list->first;
    list->first = NULL;
    list->last = NULL;
    free(node);
    return true;
  }
  list->last = list->last->prev;
  free(list->last->next);
  list->last->next = NULL;
  return true;
}

//see dll.h for details
bool list_remove_occ_first(struct llist *list, int value) {
  assert(list);
  struct node *node = list->first;
  if (!node) return false;
  if (node->value == value) {
    if (!node->next) {
      list->first = NULL;
      list->last = NULL;
      free(node);
      list->length -= 1;
      return true;
    }
    node->next->prev = NULL;
    list->first = node->next;
    free(node);
    list->length -= 1;
    return true;
  }
  node = node->next;
  while (node) {
    if (node->value == value) {
      node->prev->next = node->next;
      if (node->next) node->next->prev = node->prev;
      else list->last = node->prev;
      free(node);
      list->length -= 1;
      return true;
    }
    node = node->next;
  }
  return false;
}


//see dll.h for details
bool list_remove_occ_last(struct llist *list, int value) {
  assert(list);
  struct node *node = list->last;
  if (!node) return false;
  if (node->value == value) {
    if (!node->prev) {
      list->first = NULL;
      list->last = NULL;
      free(node);
      list->length -= 1;
      return true;
    }
    node->prev->next = NULL;
    list->last = node->prev;
    free(node);
    list->length -= 1;
    return true;
  }
  node = node->prev;
  while (node) {
    if (node->value == value) {
      node->next->prev = node->prev;
      if (node->prev) node->prev->next = node->next;
      else list->first = node->next;
      free(node);
      list->length -= 1;
      return true;
    }
    node = node->prev;
  }
  return false;
}



// DO NOT MODIFY list_print(..)!
void list_print(const struct llist *list, bool reverse) {
  assert(list);
  struct node *current = (reverse) ? list->last : list->first;
  if (current == NULL) {
    printf("List empty\n");
  } else {
    int i = (reverse) ? list->length - 1 : 0;
    while(current != NULL) {
      printf("Elem #%d/%d: %d\n", i, list->length - 1, current->value);
      if (reverse) {
        current = current->prev;
        --i;
      } else {
        current = current->next;
        ++i;
      }
    }
  }
}

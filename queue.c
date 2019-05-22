#include "queue.h"
#include "llist_q3.h"
#include <stdlib.h>
#include <assert.h>

struct queue {
  struct llist *list;
  int length;
};

//see queue.h for details
struct queue *queue_create(void) {
  struct queue *que = malloc(sizeof(struct queue));
  que->list = list_create();
  que->length = 0;
  return que;
}

//see queue.h for details
void queue_destroy(struct queue *queue) {
  assert(queue);
  list_destroy(queue->list);
  free(queue);
}

//see queue.h for details
void queue_enqueue(struct queue *queue, int value) {
  assert(queue);
  queue->length++;
  list_insert_back(queue->list,value);
}

//see queue.h for details
int queue_dequeue(struct queue *queue) {
  assert(queue);
  assert(queue->length);
  queue->length--;
  int value;
  list_remove_front(queue->list, &value);
  return value;
}
  
//see queue.h for details
int queue_front(struct queue *queue) {
  assert(queue);
  assert(queue->length);
  int value;
  list_remove_front(queue->list, &value);
  list_insert_front(queue->list, value);
  return value;
}

//see queue.h for details
bool queue_is_empty(struct queue *queue) {
  assert(queue);
  if (queue->length) return false;
  return true;
}
  
//see queue.h for details
void queue_print(const struct queue *queue) {
  assert(queue);
  list_print(queue->list, false);
}
   
  

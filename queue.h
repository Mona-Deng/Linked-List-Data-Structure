#include <stdbool.h>

struct queue;

/*
 * queue_create() creates and returns a new (empty) queue.
 * effects: allocates heap memory (caller has to free with queue_destroy(..))
 * time:    O(1)
 */
struct queue *queue_create(void);

/*
 * queue_destroy(queue) deallocates all used heap memory.
 * effects: deallocates memory
 * time:    O(n), where n is the length of the queue
 */
void queue_destroy(struct queue *queue);

/*
 * queue_enqueue(queue, value) adds [value] to [queue].
 * effects: modifies [queue]
 * time:    O(1)
 */
void queue_enqueue(struct queue *queue, int value);

/*
 * queue_dequeue(queue) removes the front element of [queue] and returns its
 *   value.
 * effects:  modifies [queue]
 * requires: [queue] is not empty
 * time:     O(1)
 */
int queue_dequeue(struct queue *queue);

/*
 * queue_front(queue) returns the front element of [queue].
 * requires: [queue] is not empty
 * time:     O(1)
 */
int queue_front(struct queue *queue);

/*
 * queue_is_empty(queue) returns true if [queue] is empty, and false otherwise.
 * time:    O(1)
 */
bool queue_is_empty(struct queue *queue);

/*
 * queue_print(queue) prints the current values in [queue] to the console.
 * effects: modifies the console
 * time:    O(n), where n is the length of the queue
 */
void queue_print(const struct queue *queue);

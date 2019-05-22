int main(void) {
  struct queue *queue;
  char cmd;
  int val;

  while(1) {
    scanf(" %c", &cmd);
    if (cmd == 'C') {            // queue_create
      queue = queue_create();
    } else if (cmd == 'D') {     // queue_destroy
      queue_destroy(queue);
    } else if (cmd == '+') {     // queue_enqueue
      scanf("%d", &val);
      queue_enqueue(queue, val);
    } else if (cmd == '-') {     // queue_dequeue
      printf("dequeue: %d\n", queue_dequeue(queue));
    } else if (cmd == '=') {     // queue_front
      printf("front: %d\n", queue_front(queue));
    } else if (cmd == '?') {     // queue_is_empty
      printf("empty?: %s\n", queue_is_empty(queue) ? "true" : "false");
    } else if (cmd == 'P') {
      queue_print(queue);
    } else if (cmd == 'Q') {     // quit program
      break;
    }
  }
  return EXIT_SUCCESS;
}

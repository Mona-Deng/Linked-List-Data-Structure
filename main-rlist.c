#include <stdio.h>
#include <stdlib.h>
#include "rlist_iter.h"
#include "rlist_rec.h"

int main(void) {
  struct llist *list = list_create();
  
  int input;
  while(scanf("%d", &input) == 1) {
    list_append(list, input);
  }
  
  char cmd;
  scanf("%c", &cmd);
  if (cmd == 'I') {
    reverse_iter(list);
  } else if (cmd == 'R') {
    reverse_rec(list);
  }
  list_print(list);
  
  list_destroy(list);
}

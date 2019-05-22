#include <stdlib.h>
#include <stdio.h>
#include "sdll.h"

int main(void) {
  struct sllist *list;
  char cmd;
  int val;

  while(1) {
    scanf(" %c", &cmd);
    if (cmd == 'C') {            // list_create
      list = list_create();
    } else if (cmd == 'D') {     // list_destroy
      list_destroy(list);
    } else if (cmd == 'I') {     // insert_value
      scanf("%d", &val);
      list_insert(list, val);
    } else if (cmd == 'R') {     // remove_value
      scanf("%d", &val);
      list_remove(list, val);
    } else if (cmd == 'P') {     // print_list: ...
      list_print(list);
    } else if (cmd == 'Q') {     // quit program
      break;
    }
  }
  return EXIT_SUCCESS;
}

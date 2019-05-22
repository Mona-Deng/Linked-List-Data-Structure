#include <stdlib.h>
#include <stdio.h>
#include "dll.h"

int main(void) {
  struct llist *dll;
  char cmd;
  int val;

  while(1) {
    scanf(" %c", &cmd);
    if (cmd == 'C') {            // list_create
      dll = list_create();
    } else if (cmd == 'D') {     // list_destroy
      list_destroy(dll);
    } else if (cmd == 'I') {     // list_insert ...
      scanf(" %c", &cmd);
      scanf("%d", &val);
      if (cmd == 'F') {          // ... _front
        list_insert_front(dll, val);
      } else if (cmd == 'B') {   // ... _back
        list_insert_back(dll, val);
      }
    } else if (cmd == 'R') {     // list_remove ...
      scanf(" %c", &cmd);
      if (cmd == 'F') {          // ... _front
        list_remove_front(dll, &val);
      } else if (cmd == 'B') {   // ... _back
        list_remove_back(dll, &val);
      } else if (cmd == 'O') {   // ... _occurance ...
        scanf(" %c", &cmd);
        scanf("%d", &val);
        if (cmd == 'F') {        // ... _first
          list_remove_occ_first(dll, val);
        } else if (cmd == 'L') { // ... _last
          list_remove_occ_last(dll, val);
        }
      }
    } else if (cmd == 'P') {     // print_list:
      scanf(" %c", &cmd);
      if (cmd == 'F') {          // (forward)
        list_print(dll, false);
      } else if (cmd == 'R') {   // (reversed)
        list_print(dll, true);
      }
    } else if (cmd == 'Q') {     // quit program
      break;
    }
  }
  return EXIT_SUCCESS;
}

#include <stdio.h>

#include "interpret.h"

#include "stack.h"

static void repl()
{
  char line[1024];
  for (;;)
  {
    printf("> ");

    if (!fgets(line, sizeof(line), stdin))
    {
      printf("\n");
      break;
    }

    interpret(line);
  }
}




int main () {
    init();
    repl();
    /* Stack* s = new_stack(10);
    stack_push(s, 10);
    stack_push(s, 20);
    stack_push(s, 30);
    stack_print(s);
    stack_pop(s);
    stack_pop(s);
    stack_print(s); */

    return 0;
}

#include <stdio.h>
#include "interpret.h" 

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

    if (interpret(line) == 1) {
        break; 
    }
  }
}

int main () {
    init(); 
    repl();
    return 0;
}

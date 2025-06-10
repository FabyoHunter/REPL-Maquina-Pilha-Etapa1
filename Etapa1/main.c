#include <stdio.h>

#include "interpret.h" 
#include "stack.h"     

extern Stack *s; 

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

    
    free_stack(s); 

    return 0;
}

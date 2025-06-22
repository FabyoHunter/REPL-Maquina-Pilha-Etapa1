#include <stdio.h>

#include "interpret.h"

#include "stack.h"
#include "list.h"

static void repl(void) {
    char line[128];
    for (;;) {
        printf("> ");
        if (!fgets(line, sizeof(line), stdin)) {
            printf("\n");
            break;
        }
        interpret(line);
    }
}

int main(void) {
    init();
    repl();
    return 0;
}

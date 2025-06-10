#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "interpret.h"
#include "stack.h"

Stack *s;

void init () {
    s = new_stack(10);
}

void interpret (const char *source) {
    char op[10];
    char arg[10];

    sscanf (source, "%s%s", op, arg);
    // printf("operação: %s\n", op);
    // printf("argumento: %s\n",  arg);

    if (strcmp(op, "push") == 0) {
        stack_push(s, atoi(arg));
    } else if (strcmp(op, "add") == 0) {
        int arg1 = stack_pop(s);
        int arg2 = stack_pop(s);
        stack_push(s, arg1 + arg2);
    } else if (strcmp(op, "sub") == 0) {
        int arg1 = stack_pop(s);
        int arg2 = stack_pop(s);
        stack_push(s, arg1 - arg2);
    } else if (strcmp(op, "div") == 0) {
        int arg1 = stack_pop(s);
        int arg2 = stack_pop(s);
        stack_push(s, arg1 / arg2);
    } else if (strcmp(op, "mul") == 0) {
        int arg1 = stack_pop(s);
        int arg2 = stack_pop(s);
        stack_push(s, arg1 * arg2);
    } else if (strcmp(op, "print") == 0) {
        int arg1 = stack_pop(s);
        printf("%d\n", arg1);
    }  else if (strcmp(op, "debug") == 0) {
        stack_print(s);
    }
}

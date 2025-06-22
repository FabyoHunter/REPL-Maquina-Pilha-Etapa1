#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "interpret.h"
#include "stack.h"
#include "list.h"

#define OP_SIZE 16
#define ARG_SIZE 32

static Stack* s = NULL;
static List* l = NULL;

void init(void) {
    if (s) free_stack(s);
    if (l) free_list(l);
    s = new_stack(32);
    l = new_list();
}

void interpret(const char *source) {
    char op[OP_SIZE] = {0};
    char arg[ARG_SIZE] = {0};

    if (!source) return;
    sscanf(source, "%15s %31s", op, arg);

    if (strcmp(op, "push") == 0) {
        int value;
        if (sscanf(arg, "%d", &value) == 0) {
            value = list_get(l, arg);
        }
        stack_push(s, value);
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
        if (arg2 != 0)
            stack_push(s, arg1 / arg2);
        else
            printf("Erro: divisão por zero\n");
    } else if (strcmp(op, "mul") == 0) {
        int arg1 = stack_pop(s);
        int arg2 = stack_pop(s);
        stack_push(s, arg1 * arg2);
    } else if (strcmp(op, "print") == 0) {
        int arg1 = stack_pop(s);
        printf("%d\n", arg1);
    } else if (strcmp(op, "debug") == 0) {
        stack_print(s);
    } else if (strcmp(op, "pop") == 0) {
        int arg1 = stack_pop(s);
        if (list_exist(l, arg)) {
            list_set(l, arg, arg1);
        } else {
            list_append(l, arg, arg1);
        }
    }
}

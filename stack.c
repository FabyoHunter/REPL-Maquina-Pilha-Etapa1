#include <stdlib.h>
#include <stdio.h>

#include "stack.h"

#define TAM 100

struct stack {
    int *v;
    int topo;
};

Stack* new_stack(int size) {
    Stack* self = malloc(sizeof(Stack));
    self -> v = malloc(sizeof(int)*size);
    self -> topo = 0;
    return self;
}

void stack_push(Stack* s, int value){
    s -> v[s -> topo++] = value;
}

int stack_pop (Stack* s){
    return s -> v[--s -> topo];
}

void stack_print(Stack* s){
    printf("------------------------------------\n");
    for (int i = 0; i < s -> topo; i++) {
        printf ("%d\n", s -> v[i]);
    }
    printf("------------------------------------\n");
}

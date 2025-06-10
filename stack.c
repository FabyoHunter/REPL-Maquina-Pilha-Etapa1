#include <stdlib.h>
#include <stdio.h>

#include "stack.h"

#define TAM 100

struct stack {
    int *v;
    int topo;
};

Stack* new_stack(int size) {
    Stack* nova_pilha = malloc(sizeof(Stack));
    nova_pilha -> v = malloc(sizeof(int)*size);
    nova_pilha -> topo = 0;
    return nova_pilha
    ;
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

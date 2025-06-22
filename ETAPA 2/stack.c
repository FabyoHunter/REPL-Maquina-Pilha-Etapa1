#include <stdlib.h>
#include <stdio.h>

#include "stack.h"

struct stack {
    int *v;
    int topo;
    int size;
};

Stack* new_stack(int size) {
    if (size <= 0) size = 10;
    Stack* self = malloc(sizeof(Stack));
    if (!self) return NULL;
    self->v = malloc(sizeof(int) * size);
    if (!self->v) {
        free(self);
        return NULL;
    }
    self->topo = 0;
    self->size = size;
    return self;
}

void stack_push(Stack* s, int value) {
    if (!s || s->topo >= s->size) return;
    s->v[s->topo++] = value;
}

int stack_pop(Stack* s) {
    if (!s || s->topo <= 0) return 0;
    return s->v[--s->topo];
}

void stack_print(const Stack* s) {
    if (!s) return;
    printf("------------------------------------\n");
    for (int i = 0; i < s->topo; i++) {
        printf("%d\n", s->v[i]);
    }
    printf("------------------------------------\n");
}

void free_stack(Stack* s) {
    if (s) {
        free(s->v);
        free(s);
    }
}

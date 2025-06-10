#ifndef stack_h
#define stack_h

typedef struct stack {
    int *v;
    int topo;
    int max_size; // Adicionei esta linha
} Stack; // A primeira declaração de typedef está aqui na linha 8

Stack* new_stack(int size);
void stack_push(Stack* s, int value);
int stack_pop (Stack* s);
void stack_print(Stack* s);

#endif

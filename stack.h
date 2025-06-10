#ifndef stack_h
#define stack_h

typedef struct stack {
    int *v;
    int topo;
    int max_size; 
} Stack; 

Stack* new_stack(int size);
void stack_push(Stack* s, int value);
int stack_pop (Stack* s);
void stack_print(Stack* s);

#endif

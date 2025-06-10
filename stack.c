#include <stdlib.h>
#include <stdio.h>
#include <limits.h> 

#include "stack.h"



Stack* new_stack(int size) {
    Stack* self = malloc(sizeof(Stack));
    if (self == NULL) {
        perror("Erro ao alocar memória para a pilha");
        exit(EXIT_FAILURE);
    }
    self->v = malloc(sizeof(int) * size);
    if (self->v == NULL) {
        perror("Erro ao alocar memória para os elementos da pilha");
        free(self); 
        exit(EXIT_FAILURE);
    }
    self->topo = 0;
    self->max_size = size; 
    return self;
}

void stack_push(Stack* s, int value){
    if (s == NULL) {
        fprintf(stderr, "Erro: Pilha não inicializada (NULL).\n");
        return;
    }
    if (s->topo >= s->max_size) {
        fprintf(stderr, "Erro: Pilha cheia (overflow)!\n");
        return; 
    }
    s->v[s->topo++] = value;
}

int stack_pop (Stack* s){
    if (s == NULL) {
        fprintf(stderr, "Erro: Pilha não inicializada (NULL).\n");
       
        exit(EXIT_FAILURE);
    }
    if (s->topo == 0) {
        fprintf(stderr, "Erro: Pilha vazia (underflow)!\n");
       
        return 0; 
    }
    return s->v[--s->topo];
}

void stack_print(Stack* s){
    if (s == NULL) {
        fprintf(stderr, "Erro: Pilha não inicializada (NULL) para impressão.\n");
        return;
    }
    printf("------------------------------------\n");
    if (s->topo == 0) {
        printf("Pilha vazia.\n");
    } else {
        for (int i = 0; i < s->topo; i++) {
            printf ("%d\n", s->v[i]);
        }
    }
    printf("------------------------------------\n");
}


void stack_print(Stack* s){ /* ... */ }

void free_stack(Stack* s) {
    if (s != NULL) {
        free(s->v); 
        free(s);    
    }
}

#include <stdlib.h> 
#include <stdio.h>  
#include <limits.h> 

#include "stack.h"

Stack* new_stack(int size) {
    Stack* self = (Stack*) malloc(sizeof(Stack)); 
    if (self == NULL) {
        perror("Erro ao alocar memória para a estrutura da pilha");
        exit(EXIT_FAILURE); 
    }

    self->v = (int*) malloc(sizeof(int) * size); 
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
        fprintf(stderr, "Erro stack_push: Pilha não inicializada (NULL).\n");
        return;
    }
    if (s->topo >= s->max_size) {
        fprintf(stderr, "Erro stack_push: Pilha cheia (overflow) - Capacidade máxima: %d.\n", s->max_size);
        return;
    }
    s->v[s->topo++] = value;
}


int stack_pop(Stack* s){
    if (s == NULL) {
        fprintf(stderr, "Erro stack_pop: Pilha não inicializada (NULL).\n");
        exit(EXIT_FAILURE); 
    }
    if (s->topo == 0) {
        fprintf(stderr, "Erro stack_pop: Pilha vazia (underflow)!\n");
      
        return 0; 
       
    }
    return s->v[--s->topo]; 
}

void stack_print(Stack* s){
    if (s == NULL) {
        fprintf(stderr, "Erro stack_print: Pilha não inicializada (NULL) para impressão.\n");
        return;
    }
    printf("------------------------------------\n");
    if (s->topo == 0) {
        printf("Pilha vazia.\n");
    } else {
       
        printf("Conteúdo da Pilha (Base ao Topo):\n");
        for (int i = 0; i < s->topo; i++) {
            printf("  [%d] %d\n", i, s->v[i]);
        }
    }
    printf("------------------------------------\n");
}


void free_stack(Stack* s) {
    if (s != NULL) {
        free(s->v); 
        free(s);    
        printf("Memória da pilha liberada.\n");
    }
}

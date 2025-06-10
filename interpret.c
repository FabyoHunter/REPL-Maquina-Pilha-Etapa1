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
    char arg_str[10]; 
    int num_args_read;
    int value1, value2;

   
    num_args_read = sscanf(source, "%9s %9s", op, arg_str);

    if (num_args_read == EOF) { 
        return;
    }

    if (strcmp(op, "push") == 0) {
        if (num_args_read < 2) {
            fprintf(stderr, "Erro: 'push' requer um argumento numérico. Ex: push 10\n");
            return;
        }
        stack_push(s, atoi(arg_str));
    } else if (strcmp(op, "add") == 0) {
       
        if (s->topo < 2) {
            fprintf(stderr, "Erro: 'add' requer 2 operandos na pilha.\n");
            return;
        }
        value1 = stack_pop(s); 
        value2 = stack_pop(s); 
        stack_push(s, value1 + value2);
    } else if (strcmp(op, "sub") == 0) {
        if (s->topo < 2) {
            fprintf(stderr, "Erro: 'sub' requer 2 operandos na pilha.\n");
            return;
        }
        value1 = stack_pop(s); 
        value2 = stack_pop(s); 
        stack_push(s, value2 - value1); 
                                       
    } else if (strcmp(op, "div") == 0) {
        if (s->topo < 2) {
            fprintf(stderr, "Erro: 'div' requer 2 operandos na pilha.\n");
            return;
        }
        value1 = stack_pop(s); 
        value2 = stack_pop(s); 
        if (value1 == 0) { 
            fprintf(stderr, "Erro: Divisão por zero!\n");
            stack_push(s, value2); 
            stack_push(s, value1); 
            return;
        }
        stack_push(s, value2 / value1);
                                       
    } else if (strcmp(op, "mul") == 0) {
        if (s->topo < 2) {
            fprintf(stderr, "Erro: 'mul' requer 2 operandos na pilha.\n");
            return;
        }
        value1 = stack_pop(s);
        value2 = stack_pop(s);
        stack_push(s, value1 * value2);
    } else if (strcmp(op, "print") == 0) {
        if (s->topo < 1) {
            fprintf(stderr, "Erro: 'print' requer 1 operando na pilha.\n");
            return;
        }
        value1 = stack_pop(s);
        printf("%d\n", value1);
    } else if (strcmp(op, "debug") == 0) {
        stack_print(s);
    } else if (strcmp(op, "clear") == 0) { 
        if (s != NULL) {
            s->topo = 0; 
            printf("Pilha limpa.\n");
        }
    }
  
    else {
        fprintf(stderr, "Comando desconhecido: '%s'\n", op);
    }
}

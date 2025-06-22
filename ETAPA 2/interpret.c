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
    if (!source || source[0] == '\0') return;

    char op[OP_SIZE] = {0};
    char arg[ARG_SIZE] = {0};

    arg[0] = '\0'; 

    sscanf(source, "%15s %31s", op, arg);

    if (strcmp(op, "push") == 0) {
        int value;
        if (sscanf(arg, "%d", &value) == 0) {
            if (list_exist(l, arg)) {
                value = list_get(l, arg);
                stack_push(s, value);
            } else {
                printf("Erro: Variavel '%s' nao encontrada.\n", arg);
                return; 
            }
        } else {
            stack_push(s, value);
        }
    } else if (strcmp(op, "add") == 0) {
        int arg1 = stack_pop(s);
        int arg2 = stack_pop(s);
        stack_push(s, arg1 + arg2);
    } else if (strcmp(op, "sub") == 0) {
        int arg1 = stack_pop(s);
        int arg2 = stack_pop(s);
        stack_push(s, arg2 - arg1);
    } else if (strcmp(op, "div") == 0) {
        int arg1 = stack_pop(s);
        int arg2 = stack_pop(s);
        if (arg1 != 0)
            stack_push(s, arg2 / arg1);
        else
            printf("Erro: divisao por zero\n");
    } else if (strcmp(op, "mul") == 0) {
        int arg1 = stack_pop(s);
        int arg2 = stack_pop(s);
        stack_push(s, arg1 * arg2);
    } else if (strcmp(op, "print") == 0) {
        int val_to_print = stack_pop(s);
        printf("%d\n", val_to_print);
    } else if (strcmp(op, "debug") == 0) {
        printf("\n--- Conteudo da Pilha ---\n");
        stack_print(s);
        printf("\n--- Variaveis --- \n");
        list_print(l);
    } else if (strcmp(op, "pop") == 0) {
        int val_from_stack = stack_pop(s);
        if (strlen(arg) > 0) { 
            if (list_exist(l, arg)) {
                list_set(l, arg, val_from_stack);
            } else {
                list_append(l, arg, val_from_stack);
            }
        }
    } else if (strcmp(op, "exit") == 0) {
        // Nenhuma ação direta aqui, a saída é controlada pelo main.c
    } else {
        printf("Erro: Instrucao desconhecida '%s'.\n", op);
    }
}

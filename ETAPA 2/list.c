#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

#define KEY_SIZE 32

struct node {
    char key[KEY_SIZE];
    int value;
    struct node* next;
};

struct list {
    struct node* first;
};

static struct node* list_find(const List* l, const char* key) {
    struct node* next = l ? l->first : NULL;
    while (next) {
        if (strncmp(next->key, key, KEY_SIZE) == 0) {
            return next;
        }
        next = next->next;
    }
    return NULL;
}

List* new_list(void) {
    List* l = calloc(1, sizeof(List));
    return l;
}

void list_append(List* l, const char* key, int value) {
    if (!l || !key) return;
    struct node* node = calloc(1, sizeof(struct node));
    strncpy(node->key, key, KEY_SIZE - 1);
    node->key[KEY_SIZE - 1] = '\0';
    node->value = value;
    node->next = l->first;
    l->first = node;
}

int list_get(const List* l, const char* key) {
    struct node* n = list_find(l, key);
    return n ? n->value : 0;
}

void list_set(List* l, const char* key, int value) {
    struct node* n = list_find(l, key);
    if (n) n->value = value;
}

int list_exist(const List* l, const char* key) {
    return list_find(l, key) != NULL;
}

void list_print(const List* l) {
    struct node* next = l ? l->first : NULL;
    while (next) {
        printf("%s -> %d\n", next->key, next->value);
        next = next->next;
    }
}

void free_list(List* l) {
    if (!l) return;
    struct node* curr = l->first;
    while (curr) {
        struct node* tmp = curr;
        curr = curr->next;
        free(tmp);
    }
    free(l);
}

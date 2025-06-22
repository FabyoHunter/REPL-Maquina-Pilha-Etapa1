#ifndef LIST_H
#define LIST_H

typedef struct list List;

List* new_list(void);
void list_append(List* s, const char* key, int value);
int list_get(const List* s, const char* key);
void list_set(List* s, const char* key, int value);
int list_exist(const List* s, const char* key);
void list_print(const List* s);
void free_list(List* s);

#endif

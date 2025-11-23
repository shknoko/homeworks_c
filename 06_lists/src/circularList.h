#pragma once
#include <stdbool.h>

typedef struct Node Node;
typedef struct List List;

List* newList();
Node* createNode(int data);
bool insert(List* list, int data, unsigned index);
bool del(List* list, unsigned index);
int isEmpty(List* list);
bool deleteList(List* list);
bool len(List* list, unsigned* res);
bool find(List* list, unsigned index, int* res);
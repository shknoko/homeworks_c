#pragma once
#include <stdbool.h>

typedef struct Stack Stack;

Stack* newStack(void);
bool isEmpty(Stack*);
void push(Stack* stack, char data);
char pop(Stack* stack);
void deleteStack(Stack* stack);
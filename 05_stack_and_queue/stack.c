#include "stack.h"
#include <stdbool.h>
#include <stdlib.h>

typedef struct StackNode
{
    char data;
    StackNode* next;
} StackNode;

typedef struct Stack 
{
    StackNode *head;
} Stack;

Stack* newStack(void)
{
    Stack* stack = calloc(1, sizeof(Stack));
    return stack;
}

bool isEmpty(Stack* stack)
{
    return stack->head == NULL;
}

void push(Stack* stack, char data)
{
    StackNode* element = (StackNode*)calloc(1, sizeof(StackNode));

    element->data = data;
    element->next = stack->head;
    stack->head = element;
}

char pop(Stack* stack)
{
    if (isEmpty(stack)) {
        return '\0';
    }

    StackNode* oldNode = stack->head;
    char data = oldNode->data;
    stack->head = stack->head->next;

    free(oldNode);

    return data;
}

void deleteStack(Stack* stack)
{
    while (!isEmpty(stack)) {
        pop(stack);
    }
    free(stack);
}

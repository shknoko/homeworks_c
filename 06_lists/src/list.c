#include "list.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct List {
    Node* head;
} List;

List* newList()
{
    List* newList = calloc(1, sizeof(List));
    return newList;
}

Node* createNode(int data)
{
    Node* newNode = calloc(1, sizeof(Node));

    if (newNode == NULL) {
        return NULL;
    }

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

bool insert(List* list, int data, unsigned index)
{
    if (list == NULL) {
        return false;
    }

    Node* newNode = createNode(data);

    if (newNode == NULL) {
        return false;
    }

    if (index == 0) {
        newNode->next = list->head;
        list->head = newNode;
        return true;
    }

    if (list->head == NULL) {
        free(newNode);
        return false;
    }

    Node* before = list->head;

    for (unsigned i = 1; i < index; i++) {
        before = before->next;

        if (before == NULL) {
            free(newNode);
            return false;
        }
    }

    Node* ahead = before->next;
    before->next = newNode;
    newNode->next = ahead;

    return true;
}

bool pop(List* list, unsigned index, int* res)
{
    if (list == NULL || list->head == NULL || res == NULL) {
        return false;
    }

    Node* before = list->head;

    if (index == 0) {
        *res = before->data;
        list->head = before->next;
        free(before);
        return true;
    }

    for (unsigned i = 1; i < index; i++) {
        before = before->next;

        if (before == NULL) {
            return false;
        }
    }

    Node* current = before->next;
    if (current == NULL) {
        return false;
    }

    *res = current->data;
    before->next = current->next;

    free(current);
    return true;
}

bool find(List* list, unsigned index, int* res)
{
    if (list == NULL || list->head == NULL || res == NULL) {
        return false;
    }

    Node* current = list->head;

    for (unsigned i = 0; i < index; i++) {
        current = current->next;

        if (current == NULL) {
            return false;
        }
    }

    *res = current->data;
    return true;
}

int indexOf(List* list, int data, unsigned* res)
{
    if (list == NULL || res == NULL) {
        return 2;
    }

    if (list->head == NULL) {
        *res = 0;
        return 1;
    }

    Node* current = list->head;

    unsigned i = 0;
    while (current != NULL && current->data < data) {
        i++;
        current = current->next;
    }

    *res = i;
    if (current == NULL || current->data != data) {
        return 1;
    }

    return 0;
}

int isEmpty(List* list)
{
    if (list == NULL) {
        return 2;
    }

    return list->head == NULL;
}

bool deleteList(List* list)
{
    if (list == NULL) {
        return true;
    }

    Node* current = list->head;

    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }

    free(list);
    return true;
}

bool len(List* list, unsigned* res)
{
    unsigned len = 0;

    if (list == NULL || res == NULL) {
        return false;
    }

    Node* current = list->head;

    while (current != NULL) {
        len++;
        current = current->next;
    }

    *res = len;
    return true;
}

bool printList(List* list, unsigned startIndex, unsigned endIndex)
{
    if (list == NULL || list->head == NULL || startIndex >= endIndex) {
        return false;
    }

    Node* current = list->head;
    for (unsigned i = 0; i < startIndex; i++) {
        current = current->next;
        if (current == NULL) {
            return false;
        }
    }

    for (unsigned i = startIndex; i < endIndex; i++) {
        printf("%d ", current->data);
        current = current->next;
        if (current == NULL) {
            break;
        }
    }
    printf("\n");

    return true;
}

#include "circularList.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

    if (list->head == NULL) {
        if (index == 0) {
            newNode->next = newNode;
            list->head = newNode;
            return true;
        }
        free(newNode);
        return false;
    }

    if (index == 0) {
        newNode->next = list->head;
        Node* current = list->head;

        while (current->next != list->head) {
            current = current->next;
        }

        current->next = newNode;
        list->head = newNode;
        return true;
    }

    Node* before = list->head;

    for (unsigned i = 1; i < index; i++) {
        before = before->next;

        if (before == list->head) {
            free(newNode);
            return false;
        }
    }

    Node* ahead = before->next;
    before->next = newNode;
    newNode->next = ahead;

    return true;
}

bool del(List* list, unsigned index)
{
    if (list == NULL || list->head == NULL) {
        return false;
    }

    Node* before = list->head;

    if (index == 0) {
        if (before->next == before) {
            free(before);
            list->head = NULL;
            return true;
        }

        Node* current = before;

        while (current->next != before) {
            current = current->next;
        }
        current->next = before->next;
        list->head = before->next;
        free(before);
        return true;
    }

    for (unsigned i = 1; i < index; i++) {
        before = before->next;

        if (before == list->head) {
            return false;
        }
    }

    Node* current = before->next;
    if (current == NULL || current == list->head) {
        return false;
    }

    before->next = current->next;
    free(current);
    return true;
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

    if (list->head != NULL) {
        Node* current = list->head->next;
        while (current != list->head) {
            Node* next = current->next;
            free(current);
            current = next;
        }
        free(list->head);
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

    if (list->head == NULL) {
        *res = 0;
        return true;
    }

    Node* current = list->head;
    len = 1;

    while (current->next != list->head) {
        len++;
        current = current->next;
    }

    *res = len;
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

        if (current == list->head) {
            return false;
        }
    }

    *res = current->data;
    return true;
}

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#define MAX_LEN 20
typedef struct Node {
    /* data */
    int key;
    char value[MAX_LEN];
    struct Node *next;
} Node;


void InitList(Node *L) {
    L = NULL;
}

void put(Node *L, int key, char value[]) {
    Node *head = L;
    Node *node;
    node = (Node *) malloc(sizeof(Node));
    node->key = key;
    strcpy(node->value, value);
    while (head != NULL) {
        if (!strcmp(head->value, value)) {
            head->key = key;
            return;
        }
        head = head->next;
    }
    if (head == L) {
        L->key = node->key;
        strcpy(L->value, node->value);
        L->next = NULL;
    } else {
        node->next = L->next;
        L->next = node;
    }
}

int get(Node *L, char value[]) {
    Node *head = L;
    while (head != NULL) {
        if (!strcmp(head->value, value)) {
            return head->key;
        }
        head = head->next;
    }
    return 0;
}

int contains(Node *L, char value[]) {
    Node *head = L;
    while (head != NULL) {
        if (!strcmp(head->value, value))
            return 1;
        head = head->next;
    }
    return 0;
}

int size(Node *L) {
    int count = 0;
    Node *head = L;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count - 1;
}

void delete(Node *L, char value[]) {
    Node *pre = L;
    Node *head = pre->next;
    while (head != NULL) {
        if (!strcmp(head->value, value)) {
            pre->next = head->next;
            free(head);
        }
        pre = head;
        head = head->next;
    }
}

void max(Node *L) {
}

void display(Node *L) {
    Node *head = L;
    while (head != NULL) {
        printf("%s:%d\n", head->value, head->key);
        head = head->next;
    }
}

void main() {
    Node L;
    InitList(&L);
    char word[10][20] = {"i", "have", "some", "eat", "and", "some", "eat", "some", "q", "e"};
    for (int i = 0; i < 10; i++) {
        if (contains(&L, word[i]))
            put(&L, get(&L, word[i]) + 1, word[i]);
        else
            put(&L, 1, word[i]);
    }
    char max[10] = " ";
    put(&L, 0, max);
    display(&L);
}

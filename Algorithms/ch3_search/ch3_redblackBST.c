#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

/*
 * RED_BLACK_TREE
 */

#define null NULL
#define RED 1
#define BLACK 0
typedef struct Node {
    int value;
    int color;
    struct Node *left, *right;
} Node;

Node *InitNode(Node *node, int value, int color) {
    node = (Node *) malloc(sizeof(Node));
    node->value = value;
    node->right = null;
    node->left = null;
    node->color = color;
    return node;
}

Node *rotateLeft(Node *node) {
    Node *x = node->right;
    node->right = x->left;
    x->left = node;
    x->color = node->color;
    return x;
}

Node *rotaleRight(Node *node) {
    Node *x = node->left;
    node->left = x->right;
    x->right = node;
    x->color = node->color;
    return x;
}

Node *switchColor(Node *node) {
    node->color = RED;
    node->left->color = BLACK;
    node->right->color = BLACK;
    return node;
}

int isRed(Node *node) {
    if (node == null)
        return null;
    return node->color == RED;
}

Node *put(Node *p, int value) {
    if (p == null) {
        p = InitNode(p, value, RED);
        return p;
    }
    int cmp = value - p->value;
    if (cmp < 0) p->left = put(p->left, value);
    else if (cmp > 0) p->right = put(p->right, value);
    else p->value = value;

    if(isRed(p->right) && (!isRed(p->left))) p = rotateLeft(p);
    if(isRed(p->left->left) && isRed(p->left)) p = rotaleRight(p);
    if(isRed(p->left) && isRed(p->right)) p = switchColor(p);
    return p;
}

int get(Node *node, int value) {
    Node *p = node;
    if (p == NULL) return null;
    int cmp = value - p->value;
    if (cmp < 0) return get(p->left, value);
    else if (cmp > 0) return get(p->right, value);
    else return p->value;
}

void delete()
{}

void deleteMin()
{}

void main() {
    Node *node = null;
//    int a[10] = {19,5,1,18,3,8,24,13,16,12};
    int a[10] = {5, 3, 8, 0, 1, 4, 34, 2, 18, 66};
    for (int i = 0; i < 10; i++)
        node = put(node, a[i]);
    display(node);
}
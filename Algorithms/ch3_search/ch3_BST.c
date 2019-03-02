#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

/*
 * BST 二叉搜索树
 */

#define null NULL
typedef struct Node {
    int value;
    int N;
    struct Node *left, *right;
} Node;

Node* InitNode(Node* node, int value) {
    node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->right = null;
    node->left = null;
    node->N = 1;
    return node;
}


int size(Node *node) {
    if (node == NULL)
        return 0;
    else return node->N;
}

Node *put(Node *node, int value) {
    Node *p = node;
    if (p==null) {
        p = InitNode(p, value);
        return p;
    } else {
        int cmp = value - p->value;
        if (cmp < 0) p->left = put(p->left, value);
        else if (cmp > 0) p->right = put(p->right, value);
        else p->value = value;
        p->N = size(p->left) + size(p->right) + 1;
        return p;
    }
}

int get(Node *node, int value) {
    Node *p = node;
    if (p == NULL) return null;
    int cmp = value - p->value;
    if (cmp < 0) return get(p->left, value);
    else if (cmp > 0) return get(p->right, value);
    else return p->value;
}

void display(Node *node) {
    if (node == null)
        return;
    printf("%d,", node->value);
    display(node->left);
    display(node->right);
}

Node* min(Node *node)
{
    while (node->left!=null)
        node = node->left;
    return node;
}

Node* deleteMin(Node* node)
{
    if(node->left==null) return node->right;
    node->left = deleteMin(node->left);
    node->N = size(node->left) + size(node->right) + 1;
    return node;
}

Node* delete(Node* node, int value)
{
    if(node==null) return null;
    int cmp = value - node->value;
    if(cmp<0) node->left = delete(node->left, value);
    else if(cmp>0) node->right = delete(node->right, value);
    else{
        if(node->right==null) return node->left;
        if(node->left==null) return node->right;
        Node *t = node;
        node = min(t->right);
        node->right = deleteMin(node);
        node->left = t->left;
    }
    node->N = size(node->left) + size(node->right) + 1;
    return node;
}

void main() {
    Node *node = null;
    int a[10] = {5, 3, 8, 0, 1, 4, 34, 2, 18, 66};
    for (int i = 0; i < 10; i++)
        node = put(node, a[i]);
}
#ifndef _TREES_H
#define _TREES_H

#include <stdlib.h>
typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} treetype;

void _insert(treetype** root, int num) {
    if (*root == NULL) {
        treetype* new_node = (treetype*)malloc(sizeof(treetype));
        new_node->data = num;
        new_node->left = NULL;
        new_node->right = NULL;
        *root = new_node;
    } else {
        if (num < (*root)->data)
            _insert(&(*root)->left, num);
        if (num > (*root)->data)
            _insert(&(*root)->right, num);
    }
}

#endif
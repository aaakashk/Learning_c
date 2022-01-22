#ifndef _TREES_H
#define _TREES_H

#include <stdio.h>
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

void _preorder_traversal(treetype* root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    _preorder_traversal(root->left);
    _preorder_traversal(root->right);
}

void _inorder_traversal(treetype* root) {
    if (root == NULL)
        return;
    _inorder_traversal(root->left);
    printf("%d ", root->data);
    _inorder_traversal(root->right);
}

void _postorder_traversal(treetype* root) {
    if (root == NULL)
        return;
    _postorder_traversal(root->left);
    _postorder_traversal(root->right);
    printf("%d ", root->data);
}

treetype* _delete(treetype* root, int num) {
    if (!root) {
        return NULL;
    } else if (num < root->data)
        root->left = _delete(root->left, num);
    else if (num > root->data)
        root->right = _delete(root->right, num);
    else  //number found
    {
        //case 1: no child
        if (!root->left && !root->right) {
            free(root);
            root = NULL;
        }
        //case 2: single child, either left or right
        //right child
        else if (root->left == NULL) {
            treetype* temp = root;
            root = root->right;
            free(temp);
        }
        //left child
        else if (root->right == NULL) {
            treetype* temp = root;
            root = root->left;
            free(temp);
        }
        //case 3: both children
        else {
            treetype* temp = root->right;
            while (temp->left != NULL)
                temp = temp->left;
            root->data = temp->data;  //temp now contains the inorder successor
            //now delete the inorder successor
            //goes to either case 1 or case 2(right child)
            root->right = _delete(root->right, temp->data);
        }
    }
    return root;
}

#endif
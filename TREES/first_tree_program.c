#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "binary_search_tree.h"

int countLeafNodes(treetype*);
int count_nodes(treetype*);
int countOneNode(treetype*);
int countLeftChild(treetype*);
// void search(treetype*, int, int*);
bool search(treetype*, int);

int main() {
    treetype* root = NULL;
    _insert(&root, 50);
    _insert(&root, 30);
    _insert(&root, 60);
    _insert(&root, 40);
    _insert(&root, 20);
    _insert(&root, 70);
    _insert(&root, 10);
    _insert(&root, 25);
    _insert(&root, 45);
    _insert(&root, 65);
    _insert(&root, 8);
    _insert(&root, 9);
    _insert(&root, 62);
    _insert(&root, 67);

    _preorder_traversal(root);
    printf("\n");
    // int c = count_nodes(root);
    // printf("count = %d\n", c);
    // c = countLeafNodes(root);
    // printf("Leaf nodes = %d\n", c);
    // c = countOneNode(root);
    // printf("Only a single leaf node = %d\n", c);
    // c = countLeftChild(root);
    // printf("Left children = %d\n", c);

    // search(root, 42, &contains);

    bool contains = search(root, 99);
    printf("Contains %d? : ", 99);
    contains ? printf("%s\n", "true") : printf("%s\n", "false");

    contains = search(root, 45);
    printf("Contains %d? : ", 45);
    contains ? printf("%s\n", "true") : printf("%s\n", "false");
}

int countLeafNodes(treetype* root) {
    if (root == NULL)
        return 0;
    if (!(root->left) && !(root->right))
        return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int count_nodes(treetype* root) {
    if (root == NULL)
        return 0;
    return count_nodes(root->left) + count_nodes(root->right) + 1;
}

int countOneNode(treetype* root) {
    if (root == NULL)
        return 0;
    if ((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL)) {
        return 1;
    }
    return countOneNode(root->left) + countOneNode(root->right);
}

int countLeftChild(treetype* root) {
    if (root == NULL)
        return 0;
    if (root->left && !(root->right)) {
        return 1;
    }
    return countLeftChild(root->left) + countLeftChild(root->right);
}

// void search(treetype* root, int num, int* is_present) {
//     if (root == NULL)
//         return;
//     if (root->data == num) {
//         *is_present = 1;
//     } else {
//         if (num < root->data)
//             search(root->left, num, is_present);
//         else if (num > root->data)
//             search(root->right, num, is_present);
//     }
// }

bool search(treetype* root, int num) {
    bool is_present = false;
    if (!root)
        return is_present;
    if (root->data == num) {
        is_present = true;
        return is_present;
    } else {
        if (num < root->data)
            is_present = search(root->left, num);
        else if (num > root->data)
            is_present = search(root->right, num);
        return is_present;
    }
}
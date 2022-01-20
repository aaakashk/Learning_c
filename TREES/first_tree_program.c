#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "binary_search_tree.h"

int count_nodes(treetype*);
int leafNodes(treetype*);
int onlyLeftChild(treetype*);
int bothChildren(treetype*);
int singleChild(treetype*);
// void search(treetype*, int, int*);
bool search(treetype*, int);
int printParent(treetype*, int);

int main() {
    treetype* root = NULL;
    _insert(&root, 50);
    _insert(&root, 30);
    _insert(&root, 60);
    _insert(&root, 20);
    _insert(&root, 40);
    _insert(&root, 45);
    _insert(&root, 25);
    _insert(&root, 10);
    _insert(&root, 8);
    _insert(&root, 9);
    _insert(&root, 70);
    _insert(&root, 65);
    _insert(&root, 62);
    _insert(&root, 67);

    _preorder_traversal(root);
    printf("\n");
    int c = singleChild(root);
    printf("Nodes with a single child = %d\n", c);
    // int p = printParent(root, 67);
    // printf("Parent : %d", p);
}
//returns total number of nodes
int count_nodes(treetype* root) {
    if (!root)
        return 0;
    return count_nodes(root->left) + count_nodes(root->right) + 1;
}
//returns total leaf nodes OR nodes that have no child
int leafNodes(treetype* root) {
    if (!root)
        return 0;
    if (!(root->left) && !(root->right))
        return 1;
    return leafNodes(root->left) + leafNodes(root->right);
}
//returns total number of nodes that have only left child
int onlyLeftChild(treetype* root) {
    int c = 0;
    if (!root)
        return 0;
    if (root->left && !(root->right))
        c = 1;
    return c + onlyLeftChild(root->left) + onlyLeftChild(root->right);
}
//returns total number of nodes that have both children
int bothChildren(treetype* root) {
    int c = 0;
    if (!root)
        return 0;
    if (root->left && root->right)
        c = 1;
    return c + bothChildren(root->left) + bothChildren(root->right);
}
//returns total number of nodes that have a single child, either left or right but NOT both
int singleChild(treetype* root) {
    int c = 0;
    if (!root)
        return 0;
    if (root->left && !(root->right))  //node has only left child
        c = 1;
    else if (!(root->left) && root->right)  //node has only right child
        c = 1;
    return c + singleChild(root->left) + singleChild(root->right);
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

int printParent(treetype* root, int num) {
    int parent_num = 0;
    printf("%d", root->data);
    if (root == NULL)
        return 0;
    if (num == root->left->data || num == root->right->data) {
        return parent_num;
    } else {
        if (num < root->data)
            parent_num = printParent(root->left, num);
        else if (num > root->data)
            parent_num = printParent(root->right, num);
        return parent_num;
    }
}

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
void printParent(treetype*, int);

int main() {
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
//search a number
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
//search a number and if found, print its parent
void printParent(treetype* root, int num) {
    if (root == NULL) {
        printf("Number not found.\n");
        return;
    }
    if (root->left && root->left->data == num) {
        printf("Parent node = %d\n", root->data);
        return;
    } else if (root->right && root->right->data == num) {
        printf("Parent node = %d\n", root->data);
        return;
    } else if (num < root->data)
        printParent(root->left, num);
    else if (num > root->data)
        printParent(root->right, num);
    else
        printf("Number is the ROOT. So, no parent.\n");
}
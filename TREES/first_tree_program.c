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
treetype* delete_node(treetype*, int);

int main() {
    treetype* root = NULL;
    _insert(&root, 50);
    _insert(&root, 30);
    _insert(&root, 60);
    _insert(&root, 20);
    _insert(&root, 40);
    _insert(&root, 42);
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
    root = delete_node(root, 30);
    _preorder_traversal(root);
    printf("\n");
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

treetype* delete_node(treetype* root, int num) {
    if (!root) {
        printf("Number not found.\n");
        return NULL;
    } else if (num < root->data)
        root->left = delete_node(root->left, num);
    else if (num > root->data)
        root->right = delete_node(root->right, num);
    else  //number found
    {
        //case 1: no child
        if (!root->left && !root->right) {
            printf("no child triggered.\n");
            free(root);
            root = NULL;
        }
        //case 2: single child, either left or right
        //right child
        else if (!(root->left)) {
            treetype* temp = root;
            root = root->right;
            free(temp);
        }
        //left child
        else if (!(root->right)) {
            treetype* temp = root;
            root = root->left;
            free(temp);
        }
        //case 3: both children
        else {
            treetype* temp = root->right;
            //loop returns the pointer to inorder successor of the root
            while (temp->left != NULL)
                temp = temp->left;
            root->data = temp->data;
            root->right = delete_node(root->right, temp->data);
        }
    }
    return root;
}
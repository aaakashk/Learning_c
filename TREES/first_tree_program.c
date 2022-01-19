#include <stdio.h>
#include <stdlib.h>

#include "binary_search_tree.h"

// void preorder_traversal(treetype*);
// void inorder_traversal(treetype*);
// void postorder_traversal(treetype*);
int countLeafNodes(treetype*);
int count_nodes(treetype*);
int countOneNode(treetype*);
int countLeftChild(treetype*);

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
    int c = count_nodes(root);
    printf("count = %d\n", c);
    c = countLeafNodes(root);
    printf("Leaf nodes = %d\n", c);
    c = countOneNode(root);
    printf("Only a single leaf node = %d\n", c);
    c = countLeftChild(root);
    printf("Left children = %d\n", c);
}

// void preorder_traversal(treetype* root) {
//     if (root == NULL)
//         return;
//     printf("%d ", root->data);
//     preorder_traversal(root->left);
//     preorder_traversal(root->right);
// }

// void inorder_traversal(treetype* root) {
//     if (root == NULL)
//         return;
//     inorder_traversal(root->left);
//     printf("%d ", root->data);
//     inorder_traversal(root->right);
// }

// void postorder_traversal(treetype* root) {
//     if (root == NULL)
//         return;
//     postorder_traversal(root->left);
//     postorder_traversal(root->right);
//     printf("%d ", root->data);
// }

int countLeafNodes(treetype* root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
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
    if (root->left != NULL && root->right == NULL) {
        return 1;
    }
    return countLeftChild(root->left) + countLeftChild(root->right);
}

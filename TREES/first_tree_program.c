#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} treetype;

void preorder_traversal(treetype*);
void inorder_traversal(treetype*);
void postorder_traversal(treetype*);
int countLeafNodes(treetype*);
int count_nodes(treetype*);
int countOneNode(treetype*);
int countLeftChild(treetype*);
void insert_node(treetype**, int);

int main() {
    treetype* root = NULL;
    insert_node(&root, 50);
    insert_node(&root, 30);
    insert_node(&root, 60);
    insert_node(&root, 40);
    insert_node(&root, 20);
    insert_node(&root, 70);
    insert_node(&root, 10);
    insert_node(&root, 25);
    insert_node(&root, 45);
    insert_node(&root, 65);
    insert_node(&root, 8);
    insert_node(&root, 9);
    insert_node(&root, 62);
    insert_node(&root, 67);

    preorder_traversal(root);
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

void preorder_traversal(treetype* root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

void inorder_traversal(treetype* root) {
    if (root == NULL)
        return;
    inorder_traversal(root->left);
    printf("%d ", root->data);
    inorder_traversal(root->right);
}

void postorder_traversal(treetype* root) {
    if (root == NULL)
        return;
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    printf("%d ", root->data);
}

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

void insert_node(treetype** root, int num) {
    if (*root == NULL) {
        treetype* new_node = malloc(sizeof(treetype));
        new_node->data = num;
        new_node->left = NULL;
        new_node->right = NULL;
        *root = new_node;
    } else {
        if (num < (*root)->data)
            insert_node(&(*root)->left, num);
        if (num > (*root)->data)
            insert_node(&(*root)->right, num);
    }
}
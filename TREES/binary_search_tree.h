#ifndef _TREES_H
#define _TREES_H

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} treetype;

void _insert(treetype**, int);

#endif
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} nodetype;

void create(nodetype** start, int num) {
    nodetype* ptr = (nodetype*)malloc(sizeof(nodetype));
    ptr->data = num;
    ptr->next = NULL;
    if (*start == NULL)
        *start = ptr;
    else {
        nodetype* temp = *start;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = ptr;
    }
}

void display(nodetype* start) {
    int count = 0;
    while (start->next != NULL) {
        printf("%d ", start->data);
        count++;
        start = start->next;
    }
    printf("\ncount = %d", count);
}

int main() {
    //int number;
    nodetype* start = NULL;
    create(&start, 1);
    create(&start, 2);
    create(&start, 3);
    create(&start, 4);
    create(&start, 5);
    // if (start == NULL) {
    //     printf("List empty.\n");
    // } else {
    //     display(start);
    // }
    display(start);
}
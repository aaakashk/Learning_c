//the llinked list should be in ascending order as the new nodes are inserted
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} nodetype;

nodetype* left_insert(nodetype* start, int num);
nodetype* right_insert(nodetype* start, int num);
nodetype* middle_insert(nodetype* start, int num);
void display(nodetype* start);

int main() {
    nodetype* start = NULL;
    // start = left_insert(start, 13);
    // start = left_insert(start, 10);
    // start = left_insert(start, 6);
    // start = left_insert(start, 5);
    // start = right_insert(start, 18);
    // start = middle_insert(start, 7);
    // start = left_insert(start, 1);
    // start = right_insert(start, 20);
    // start = middle_insert(start, 8);
    int choice, number;
    do {
        printf(
            "1. Insert a number.\n"
            "2. Display the linked list.\n"
            "3. Exit the program.\n"
            "Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the number: ");
                scanf("%d", &number);
                if (start == NULL)
                    start = left_insert(start, number);
                else {
                    if (number <= start->data) {
                        start = left_insert(start, number);
                        display(start);
                    } else if (number > start->data) {
                        nodetype* b = start;
                        while (b->data <= number && b->next != NULL)
                            b = b->next;
                        start = middle_insert(start, number);
                        display(start);
                    } else
                        printf("------------------------------\n");
                }
                break;
            case 2:
                if (start == NULL)
                    printf("The list is empty.");
                else
                    display(start);
                break;
            case 3:
                exit(0);
            default:
                printf("Wrong choice. Enter again.\n");
        }

    } while (1);

    //    display(start);
}

nodetype* left_insert(nodetype* start, int num) {
    nodetype* ptr = (nodetype*)malloc(sizeof(nodetype));
    if (ptr == NULL)
        printf("Device didn't provide enough memory.\n");
    else {
        ptr->data = num;
        if (start == NULL)
            ptr->next = NULL;
        else {
            ptr->next = start;
        }
        start = ptr;
    }
    return start;
}

nodetype* right_insert(nodetype* start, int num) {
    nodetype* ptr = (nodetype*)malloc(sizeof(nodetype));
    if (ptr == NULL)
        printf("Device didn't provide enough memory.\n");
    else {
        ptr->data = num;
        ptr->next = NULL;
        if (start == NULL)
            start = ptr;
        else {
            nodetype* temp = start;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = ptr;
        }
    }
    return start;
}

nodetype* middle_insert(nodetype* start, int num) {
    nodetype* ptr = (nodetype*)malloc(sizeof(nodetype));
    ptr->data = num;
    nodetype* temp = start;
    nodetype* temp_prev;
    while (temp->data <= num && temp->next != NULL) {
        temp_prev = temp;
        temp = temp->next;
    }
    if (temp->data <= num) {
        ptr->next = temp_prev->next;
        temp_prev->next = ptr;
    }
    if (temp->next == NULL) {
        temp->next = ptr;
        ptr->next = NULL;
    }
    return start;
}

void display(nodetype* start) {
    while (start != NULL) {
        printf("%d ", start->data);
        start = start->next;
    }
    printf("\n");
}
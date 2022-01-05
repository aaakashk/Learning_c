#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} nodetype;

void insert(nodetype**);
void display(nodetype*);

int main() {
    nodetype* start = NULL;
    int choice;
    do {
        printf(
            "1. Insert a number.\n"
            "2. Display the list.\n"
            "3. Exit.\n"
            "Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insert(&start);
                break;
            case 2:
                if (start == NULL)
                    printf("The list is empty.\n");
                else
                    display(start);
                break;
            case 3:
                exit(0);
            default:
                printf("Wrong choice. Enter again.\n");
        }
    } while (1);
}

void insert(nodetype** head) {
    nodetype* ptr = (nodetype*)malloc(sizeof(nodetype));
    if (ptr == NULL)
        printf("Not enough memory.\n");
    else {
        int num;
        printf("Enter the number: ");
        scanf("%d", &num);
        ptr->data = num;
        ptr->next = NULL;
        if (*head == NULL)
            *head = ptr;
        else {
            nodetype* temp = *head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = ptr;
        }
    }
}

void display(nodetype* h) {
    printf("-------------------------------------------\n");
    while (h != NULL) {
        printf("%d ", h->data);
        h = h->next;
    }
    printf("\n");
    printf("-------------------------------------------\n");
}
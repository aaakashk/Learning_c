#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} nodetype;

nodetype* insert(nodetype*);
void display(nodetype*);

int main() {
    nodetype* last = NULL;
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
                last = insert(last);
                break;
            case 2:
                if (last == NULL)
                    printf("The list is empty.\n");
                else
                    display(last);
                break;
            case 3:
                exit(0);
            default:
                printf("Wrong option. Enter again.\n");
        }
    } while (1);
}

nodetype* insert(nodetype* tail) {
    nodetype* ptr = (nodetype*)malloc(sizeof(nodetype));
    if (ptr == NULL)
        printf("Not enough memory.\n");
    else {
        int num;
        printf("Enter the number: ");
        scanf("%d", &num);
        ptr->data = num;
        if (tail == NULL)
            ptr->next = ptr;
        else {
            ptr->next = tail->next;
            tail->next = ptr;
        }
        tail = ptr;
    }
    return tail;
}

void display(nodetype* tail) {
    nodetype* start = tail->next;
    do {
        printf("%d ", start->data);
        start = start->next;
    } while (start != tail->next);
    printf("\n");
}
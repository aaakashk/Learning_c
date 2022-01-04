//the llinked list should be in ascending order as the new nodes are inserted
#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node* next;
} nodetype;

nodetype* insert(nodetype* start, int num);
void display(nodetype* start);

int main() {
    nodetype* start = NULL;
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
                start = insert(start, number);
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
}

nodetype* insert(nodetype* start, int num) {
    nodetype* ptr = (nodetype*)malloc(sizeof(nodetype));
    ptr->data = num;
    ptr->next = NULL;
    if (start == NULL) {
        start = ptr;
    } else {
        if (num <= start->data) {
            ptr->next = start;
            start = ptr;
        } else {
            nodetype* r = start;
            nodetype* s;
            while (r->data <= num && r->next != NULL) {
                s = r;
                r = r->next;
            }
            if (num > r->data && r->next == NULL) {
                r->next = ptr;
            } else {
                ptr->next = s->next;
                s->next = ptr;
            }
        }
    }
    return start;
}

void display(nodetype* start) {
    printf("-----------------------------------------\n");
    while (start != NULL) {
        printf("%d ", start->data);
        start = start->next;
    }
    printf("\n-----------------------------------------\n");
}

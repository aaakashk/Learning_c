#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
} nodetype;

void insert(nodetype**, nodetype**);
void display(nodetype*);

void sort(nodetype*);

int main() {
    nodetype *head = NULL, *tail = NULL;
    int choice;
    do {
        printf(
            "1. Insert a number.\n"
            "2. Display the list.\n"
            "3. Sort the list and display.\n"
            "4. Exit.\n"
            "Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insert(&head, &tail);
                break;
            case 2:
                if (head == NULL && tail == NULL)
                    printf("The list is empty.\n");
                else {
                    display(head);
                }
                break;
            case 3:
                if (head == NULL && tail == NULL)
                    printf("The list is empty.\n");
                else {
                    sort(head);
                    printf("The sorted list is : \n");
                    display(head);
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Wrong choice. Enter again.\n");
        }
    } while (1);
}

void insert(nodetype** h, nodetype** t) {
    nodetype* ptr = (nodetype*)malloc(sizeof(nodetype));
    if (ptr == NULL)
        printf("Not enough memory.\n");
    else {
        int num;
        printf("Enter the number: ");
        scanf("%d", &num);
        ptr->data = num;
        ptr->next = NULL;
        ptr->prev = NULL;
        if (*h == NULL)
            *h = *t = ptr;
        else {
            (*t)->next = ptr;
            ptr->prev = *t;
            *t = ptr;
        }
    }
}

void display(nodetype* start) {
    while (start != NULL) {
        printf("%d ", start->data);
        start = start->next;
    }
    printf("\n");
}
//selection sort algo
void sort(nodetype* h) {
    int min;
    nodetype *j, *pos;
    while (h != NULL) {
        min = h->data;
        pos = h;
        j = h->next;
        while (j != NULL) {
            if (j->data < min) {
                min = j->data;
                pos = j;
            }
            j = j->next;
        }
        if (pos != h) {
            pos->data = h->data;
            h->data = min;
        }
        h = h->next;
    }
}
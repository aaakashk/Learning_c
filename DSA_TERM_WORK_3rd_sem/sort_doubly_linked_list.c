#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
} nodetype;

void insert(nodetype**, nodetype**);
void display(nodetype*);
//void count_nodes(nodetype*, int*);
int _count_nodes(nodetype*);

//void sort(nodetype**, nodetype**);

int main() {
    nodetype *head = NULL, *tail = NULL;
    int choice, count = 0;
    do {
        printf(
            "1. Insert a number.\n"
            "2. Display the list.\n"
            "3. Sort the list and display.\n"
            "4. Exit.\n"
            "5. Count the nodes.\n"
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
            case 5:
                printf("Count = %d\n", _count_nodes(head));
                break;
            // case 3:
            //     if (head == NULL && tail == NULL)
            //         printf("The list is empty.\n");
            //     else {
            //         sort(&head, &tail);
            //         printf("The sorted list is : \n");
            //         display(head);
            //     }
            //     break;
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

// void count_nodes(nodetype* h, int* c) {
//     while (h != NULL) {
//         (*c)++;
//         h = h->next;
//     }
// }

int _count_nodes(nodetype* h) {
    int count = 0;
    while (h != NULL) {
        count++;
        h = h->next;
    }
    return count;
}
//void sort(nodetype** h, nodetype** t) {
//}
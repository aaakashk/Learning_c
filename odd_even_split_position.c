#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} nodetype;

void insert(nodetype**);
void display(nodetype*);

void odd_even_split(nodetype**, nodetype**, nodetype**);

int main() {
    nodetype *start = NULL, *odd_start = NULL, *even_start = NULL;
    int choice, number;

    do {
        printf(
            "1. Insert a number.\n"
            "2. Display the original list.\n"
            "3. Split the list through odd and even positions and display them.\n"
            "4. Exit.\n"
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
                odd_even_split(&start, &odd_start, &even_start);

                if (odd_start == NULL && even_start == NULL)
                    printf("The original list is empty.\n");
                if (even_start == NULL)
                    printf("A single node present.\n");
                printf("ODD POSITON NODE'S LIST: \n");
                display(odd_start);
                printf("\n");
                printf("EVEN POSITON NODE'S LIST: \n");
                display(even_start);
                break;
            case 4:
                printf("Program terminated.\n");
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
    if (h == NULL)
        printf("The list is empty.\n");
    else {
        printf("-------------------------------------------\n");
        while (h != NULL) {
            printf("%d ", h->data);
            h = h->next;
        }
        printf("\n");
        printf("-------------------------------------------\n");
    }
}

void odd_even_split(nodetype** start, nodetype** odd_head, nodetype** even_head) {
    nodetype* temp = *start;
    int c = 1;
    while (temp != NULL) {
        if (c % 2 == 0) {
            nodetype* even_pos = (nodetype*)malloc(sizeof(nodetype));
            even_pos->data = temp->data;
            even_pos->next = NULL;
            if (*even_head == NULL)
                *even_head = even_pos;
            else {
                nodetype* r = *even_head;
                while (r->next != NULL) {
                    r = r->next;
                }
                r->next = even_pos;
            }
        } else {
            nodetype* odd_pos = (nodetype*)malloc(sizeof(nodetype));
            odd_pos->data = temp->data;
            odd_pos->next = NULL;
            if (*odd_head == NULL)
                *odd_head = odd_pos;
            else {
                nodetype* s = *odd_head;
                while (s->next != NULL)
                    s = s->next;
                s->next = odd_pos;
            }
        }

        c += 1;
        temp = temp->next;
    }
}

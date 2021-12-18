#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int info;
    struct node *next;
} nodetype;

nodetype *insert(nodetype *, int);
void display(nodetype *);

int main() {
    nodetype *start = NULL;
    int number, choice;
    do {
        printf(
            "1. Insert a node.\n"
            "2. Display the list.\n"
            // "3. Split the list according to odd and even positions.\n"
            // "4. Display the splitted list.\n"
            "5. Exit.\n"
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
                    printf("The list is empty. Nothing to print.\n");
                else
                    display(start);
                break;
            case 5:
                printf("The program was terminated.\n");
                exit(1);
            default:
                printf("Wrong option. Choose again.\n");
        }
    } while (1);
}

nodetype *insert(nodetype *start, int number) {
    nodetype *ptr = (nodetype *)malloc(sizeof(nodetype));
    ptr->info = number;
    ptr->next = NULL;
    if (start == NULL)
        start = ptr;
    else {
        nodetype *temp = start;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = ptr;
    }
    return start;
}

void display(nodetype *start) {
    while (start != NULL) {
        printf("%d ", start->info);
        start = start->next;
    }
    printf("\n");
}
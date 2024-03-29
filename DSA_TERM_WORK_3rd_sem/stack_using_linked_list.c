//implement stack using single pointer in linked list

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} nodetype;

nodetype* push(nodetype* top);
nodetype* pop(nodetype* top);
void display(nodetype* top);

int main() {
    nodetype* top = NULL;
    int choice, number;
    do {
        printf(
            "1. PUSH()\n"
            "2. POP()\n"
            "3. PEEK()\n"
            "4. DISPLAY\n"
            "5. EXIT\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                top = push(top);
                break;
            case 2:
                if (top == NULL)
                    printf("The stack is empty.\n");
                else
                    top = pop(top);
                break;
            case 3:
                if (top == NULL)
                    printf("The stack is empty.\n");
                else
                    printf("%d\n", top->data);
                break;
            case 4:
                if (top == NULL)
                    printf("The stack is empty.\n");
                else
                    display(top);
                break;
            case 5:
                exit(0);
            default:
                printf("Wrong choice. Enter again.\n");
        }
    } while (1);
}

nodetype* push(nodetype* top) {
    nodetype* ptr = (nodetype*)malloc(sizeof(nodetype));
    if (ptr == NULL)
        printf("Not enough memory.\n");
    else {
        printf("Enter the number: ");
        scanf("%d", &ptr->data);
        ptr->next = top;
        top = ptr;
    }
    return top;
}

nodetype* pop(nodetype* top) {
    nodetype* temp = top;
    top = top->next;
    printf("Deleted: %d\n", temp->data);
    free(temp);
    return top;
}

void display(nodetype* top) {
    while (top != NULL) {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}
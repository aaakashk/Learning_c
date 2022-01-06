//implement stack using double pointers in linked list

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} nodetype;

void push(nodetype** top);
void pop(nodetype** top);
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
                push(&top);
                break;
            case 2:
                if (top == NULL)
                    printf("The stack is empty.\n");
                else
                    pop(&top);
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

void push(nodetype** top) {
    nodetype* ptr = (nodetype*)malloc(sizeof(nodetype));
    if (ptr == NULL)
        printf("Not enough memory.\n");
    else {
        int num;
        printf("Enter the number: ");
        scanf("%d", &num);
        ptr->data = num;
        ptr->next = NULL;
        if (*top == NULL)
            *top = ptr;
        else {
            ptr->next = *top;
            *top = ptr;
        }
    }
}

void pop(nodetype** top) {
    nodetype* temp = *top;
    if ((*top)->next == NULL)
        *top = NULL;
    else
        *top = (*top)->next;
    printf("Deleted: %d\n", temp->data);
    free(temp);
}

void display(nodetype* top) {
    while (top != NULL) {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} nodetype;

void insert(nodetype**);
void delete (nodetype**, int);
void display(nodetype*);
nodetype* reverse_list(nodetype*);

int main() {
    nodetype* start = NULL;
    int choice, number;
    do {
        printf(
            "1. Insert a number.\n"
            "2. Delete a number.\n"
            "3. Display the list.\n"
            "4. Reverse the list.\n"
            "5. Exit.\n"
            "Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insert(&start);
                break;
            case 2:
                if (start == NULL)
                    printf("The list is empty. Nothing to delete.\n");
                else {
                    printf("Enter the number to delete: ");
                    scanf("%d", &number);
                    delete (&start, number);
                }
                break;
            case 3:
                if (start == NULL)
                    printf("The list is empty.\n");
                else
                    display(start);
                break;
            case 4:
                start = reverse_list(start);
                printf("The list is now reversed.\n");
                display(start);  //optional function call
                break;
            case 5:
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

void delete (nodetype** head, int num) {
    nodetype* temp = *head;
    //single node and number found
    if ((*head)->next == NULL && (*head)->data == num) {
        free(temp);
        *head = NULL;
        printf("Deleted: %d\n", num);
    } else {
        nodetype* prev = temp;
        while (temp->data != num && temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        if (temp->data != num)
            printf("Number not found.\n");
        else {
            //number found in the first node
            if (temp == *head)
                *head = (*head)->next;
            else  //number found in between or in the end
                prev->next = temp->next;
            free(temp);
            printf("Deleted: %d\n", num);
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

//reverses the singly linked list
nodetype* reverse_list(nodetype* current) {
    nodetype* prev = NULL;
    nodetype* _next = NULL;
    while (current != NULL) {
        _next = current->next;
        current->next = prev;
        prev = current;
        current = _next;
    }
    return prev;
}

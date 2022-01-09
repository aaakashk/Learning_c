#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} nodetype;

nodetype* insert(nodetype*);
void check_palindrome(nodetype*);
void display(nodetype*);

int main() {
    nodetype* start = NULL;
    int choice;
    do {
        printf(
            "1. Insert a number.\n"
            "2. Check for palindrome list.\n"
            "3. Display the list.\n"
            "4. Exit.\n"
            "Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                start = insert(start);
                break;
            case 2:
                check_palindrome(start);
                break;
            case 3:
                if (start == NULL)
                    printf("The list is empty.\n");
                else
                    display(start);
                break;
            case 4:
                exit(0);
            default:
                printf("Wrong choice. Enter again.\n");
        }
    } while (1);
}

nodetype* insert(nodetype* start) {
    nodetype* ptr = (nodetype*)malloc(sizeof(nodetype));
    if (ptr == NULL)
        printf("Not enough memory.\n");
    else {
        int num;
        printf("Enter a number:");
        scanf("%d", &num);
        ptr->data = num;
        ptr->next = NULL;
        if (start == NULL)
            start = ptr;
        else {
            nodetype* temp = start;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = ptr;
        }
    }
    return start;
}

void display(nodetype* start) {
    while (start != NULL) {
        printf("%d ", start->data);
        start = start->next;
    }
    printf("\n");
}

void check_palindrome(nodetype* start) {
    nodetype* t1 = start;
    int flag = 1;
    int count = 0;
    while (start != NULL) {
        count++;
        start = start->next;
    }
    printf("Count = %d\n", count);
    int i = 0;
    while (i < count / 2) {
        int j = 0;
        nodetype* t2 = start;
        while (j < count - 1 - i) {
            t2 = t2->next;
            j++;
        }
        if (t1->data != t2->data) {
            flag = 0;
            break;
        }
        t1 = t1->next;
        i++;
    }
    if (flag == 1)
        printf("The list is palindrome.\n");
    else
        printf("The list is not palindrome.\n");
}
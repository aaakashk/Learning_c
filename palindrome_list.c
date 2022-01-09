#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} nodetype;

nodetype* insert(nodetype*);
bool check_palindrome(nodetype*);
void display(nodetype*);

int main() {
    nodetype* start = NULL;
    bool is_palindrome;
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
                is_palindrome = check_palindrome(start);
                if (is_palindrome)
                    printf("THE LIST IS PALINDROME.\n");
                else
                    printf("THE LIST IS NOT PALINDROME.\n");
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
        printf("%d->", start->data);
        start = start->next;
    }
    printf("NULL\n");
}

bool check_palindrome(nodetype* start) {
    nodetype* c = start;  //a pointer to count
    int count = 0;
    while (c != NULL) {
        count++;
        c = c->next;
    }
    nodetype* t1 = start;  //a pointer for the first half
    for (int i = 0; i < count / 2; i++) {
        nodetype* t2 = start;  //a pointer for the second half
        for (int j = 0; j < count - 1 - i; j++)
            t2 = t2->next;
        if (t1->data != t2->data) {
            return false;
        }
        t1 = t1->next;
    }
    return true;
}

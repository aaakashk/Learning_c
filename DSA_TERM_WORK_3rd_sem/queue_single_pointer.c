//implement queue through linked list using single pointer

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} nodetype;

nodetype* enqueue(nodetype*);
nodetype* dequeue(nodetype*);
void display(nodetype*);

int main() {
    int choice;
    nodetype* h = NULL;
    do {
        printf(
            "1. ENQUEUE\n"
            "2. DEQUEUE\n"
            "3. PEEK\n"
            "4. DISPLAY\n"
            "5. EXIT\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                h = enqueue(h);
                break;
            case 2:
                if (h == NULL)
                    printf("The queue is empty.\n");
                else
                    h = dequeue(h);
                break;
            case 3:
                if (h == NULL)
                    printf("The queue is empty.\n");
                else
                    printf(
                        "-----\n"
                        "%d\n"
                        "-----\n",
                        h->data);
                break;
            case 4:
                if (h == NULL)
                    printf("The queue is empty.\n");
                else
                    display(h);
                break;
            case 5:
                exit(0);
            default:
                printf("Wrong choice. Enter again.\n");
        }

    } while (1);
}

nodetype* enqueue(nodetype* h) {
    nodetype* ptr = (nodetype*)malloc(sizeof(nodetype));
    if (ptr == NULL)
        printf("Not enough memory.\n");
    else {
        int num;
        printf("Enter the number: ");
        scanf("%d", &num);
        ptr->data = num;
        ptr->next = NULL;
        if (h == NULL)
            h = ptr;
        else {
            nodetype* temp = h;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = ptr;
        }
    }
    return h;
}

nodetype* dequeue(nodetype* h) {
    nodetype* temp = h;
    if (h->next == NULL)
        h = NULL;
    else
        h = h->next;
    printf(
        "------------\n"
        "Deleted: %d\n"
        "------------\n",
        temp->data);
    free(temp);
    return h;
}

void display(nodetype* h) {
    printf("--------------------------------\n");
    while (h != NULL) {
        printf("%d ", h->data);
        h = h->next;
    }
    printf("\n");
    printf("--------------------------------\n");
}
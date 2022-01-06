#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node* next;
} nodetype;

nodetype* create_list(nodetype*, int);
void display(nodetype*);
void display_same_data(nodetype*, nodetype*);

int main() {
    nodetype *p_head = NULL, *q_head = NULL;
    int number1, number2, n;
    printf("Enter the number of nodes of p list.");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter the number: ");
        scanf("%d", &number1);
        p_head = create_list(p_head, number1);
    }
    printf("P: ");
    display(p_head);

    printf("Enter the number of nodes of q list.");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter the number: ");
        scanf("%d", &number2);
        q_head = create_list(q_head, number2);
    }
    printf("Q: ");
    display(q_head);

    printf("=========================================\n");
    display_same_data(p_head, q_head);
}

nodetype* create_list(nodetype* start, int num) {
    nodetype* ptr = (nodetype*)malloc(sizeof(nodetype));
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
    return start;
}

void display(nodetype* start) {
    while (start != NULL) {
        printf("%d ", start->data);
        start = start->next;
    }
    printf("\n");
}

void display_same_data(nodetype* p_head, nodetype* q_head) {
    while (p_head != NULL) {
        nodetype* s = q_head;
        while (s != NULL) {
            if (s->data == p_head->data)
                printf("%d ", p_head->data);
            s = s->next;
        }
        p_head = p_head->next;
    }
}

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} nodetype;

void create(nodetype** start, int num) {
    nodetype* ptr = (nodetype*)malloc(sizeof(nodetype));
    ptr->data = num;
    ptr->next = NULL;
    if (*start == NULL)
        *start = ptr;
    else {
        nodetype* temp = *start;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = ptr;
    }
}

void create_odd_even_list(nodetype** start, nodetype** odd, nodetype** even) {
    int count = 0;
    while (*start != NULL) {
        count++;
        *start = (*start)->next;
    }
    printf("\ncount = %d", count);
    nodetype* temp = *start;
    int c = 1;
    while (temp != NULL && c <= count) {
        if (c % 2 == 0) {
            nodetype* ptr_even = (nodetype*)malloc(sizeof(nodetype));
            ptr_even->data = temp->data;
            ptr_even->next = NULL;
            if (c == 2)
                *even = ptr_even;
            else {
                nodetype* e = *even;
                while (e->next != NULL) {
                    e = e->next;
                }
                e->next = ptr_even;
            }

        } else {
            nodetype* ptr_odd = (nodetype*)malloc(sizeof(nodetype));
            ptr_odd->data = temp->data;
            ptr_odd->next = NULL;
            if (c == 1)
                *odd = ptr_odd;
            else {
                nodetype* o = *odd;
                while (o->next != NULL) {
                    o = o->next;
                }
                o->next = ptr_odd;
            }
        }
        c++;
        temp = temp->next;
    }
}

// void display_odd_even(nodetype* odd, nodetype* even) {
//     while (odd != NULL) {
//         printf("%d ", odd->data);
//         odd = odd->next;
//     }
//     while (even != NULL) {
//         printf("%d ", even->data);
//         even = even->next;
//     }
// }

void display(nodetype* start) {
    while (start != NULL) {
        printf("%d ", start->data);
        start = start->next;
    }
}

int main() {
    //int number;
    nodetype *start = NULL, *odd = NULL, *even = NULL;
    create(&start, 1);
    create(&start, 2);
    create(&start, 3);
    create(&start, 4);
    create(&start, 5);
    display(start);
    create_odd_even_list(&start, &odd, &even);
    //display_odd_even(odd, even);
    printf("\n");
    display(odd);
    printf("\n");
    display(even);
}
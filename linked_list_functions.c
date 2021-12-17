#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int info;
    struct node *next;
} nodetype;

nodetype *insert(nodetype *, int num);
void display(nodetype *);
int is_empty(nodetype *);
nodetype *delete (nodetype *, int key);
int count_nodes(nodetype *start);
void count_nodes_no_return(nodetype *start, int *count);
nodetype *search_and_delete_rest(nodetype *start, int num);
nodetype *insert_from_left(nodetype *start, int num);
int largest_number(nodetype *start);
nodetype *split_list(nodetype *start, int k);
void display_both_lists(nodetype *start, nodetype *new_list_head);
void middle_node(nodetype *);

int main() {
    nodetype *start = NULL, *new_list_head = NULL;
    int choice, key, number, count = 0, num_to_search_and_delete, node_number;
    do {
        printf(
            "1. Insert a node\n"
            "2. Insert a node from left\n"
            "3. display the numbers\n"
            "4. Delete a number\n"
            "5. Count the nodes\n"
            "6. Count the nodes without return type function\n"
            "7. Search the number and delete every node after that number\n"
            "8. Print the largest number in the list\n"
            "9. Enter the node number where the list splits\n"
            "10. Display both lists\n"
            "11. Stop the program.\n"
            "12. Print the middle node.\n"
            "Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the info: ");
                scanf("%d", &number);
                start = insert(start, number);
                break;
            case 2:
                printf("Enter the info: ");
                scanf("%d", &number);
                start = insert_from_left(start, number);
                break;
            case 3:
                if (is_empty(start) == 1)
                    printf("The list is empty.\n");
                else
                    display(start);
                break;
            case 4:
                if (is_empty(start) == 1)
                    printf("List is empty. Nothing to delete.\n");
                else {
                    printf("Enter the number you want to delete: ");
                    scanf("%d", &key);
                    start = delete (start, key);
                }
                break;
            case 5:
                printf("The number of nodes are: %d\n", count_nodes(start));
                break;
            case 6:
                count_nodes_no_return(start, &count);
                printf("The number of nodes are: %d\n", count);
                break;
            case 7:
                if (is_empty(start) == 1)
                    printf("The list is empty.\n");
                else {
                    printf("Enter number to search and delete everything after that number: ");
                    scanf("%d", &num_to_search_and_delete);
                    start = search_and_delete_rest(start, num_to_search_and_delete);
                }
                break;
            case 8:
                if (is_empty(start) == 1)
                    printf("The list is empty.\n");
                else
                    printf("The largest number is: %d", largest_number(start));

                break;
            case 9:
                if (start == NULL)
                    printf("The list is empty. Can't splilt an empty list.\n");
                else if (start->next == NULL)
                    printf("Only 1 node is there, so can't split really.\n");
                else {
                    printf("Enter the node number from where the list splits: ");
                    scanf("%d", &node_number);
                    new_list_head = split_list(start, node_number);
                }
                break;
            case 10:
                if (is_empty(start) == 1)
                    printf("The list is empty.\n");
                else
                    display_both_lists(start, new_list_head);
                break;
            case 11:
                printf("The program was terminated.\n");
                exit(1);
            case 12:
                if (is_empty(start) == 1)
                    printf("The list is empty.\n");
                else
                    middle_node(start);
                break;
            default:
                printf("Wrong choice.\n");
        }
    } while (1);
    return 0;
}
//insert a node
nodetype *insert(nodetype *start, int num) {
    nodetype *p = (nodetype *)malloc(sizeof(nodetype));

    p->info = num;
    if (is_empty(start) == 1)
        start = p;
    else {
        nodetype *t = start;
        while (t->next != NULL)
            t = t->next;
        t->next = p;
    }
    p->next = NULL;
    return start;
}
//print the list
void display(nodetype *start) {
    while (start != NULL) {
        printf("%d ", start->info);
        start = start->next;
    }
    printf("\n");
}
//checks whether the list is empty or not
int is_empty(nodetype *start) {
    if (start == NULL)
        return 1;
    else
        return 0;
}
//delete a single node that contains the inputted number
nodetype *delete (nodetype *start, int key) {
    nodetype *p = start, *t = start;
    if (start->next == NULL) {
        free(p);
        start = NULL;
    } else {
        while (p->info != key && p->next != NULL) {
            t = p;
            p = p->next;
        }
        if (p->info == key) {
            printf("Deleted: %d\n", key);
            if (start == p)
                start = start->next;
            else
                t->next = p->next;
            free(p);
        } else
            printf("Number not found.\n");
    }
    return start;
}
//count with return type function
int count_nodes(nodetype *start) {
    int count = 0;
    while (start != NULL) {
        count++;
        start = start->next;
    }
    return count;
}
//count without return type function
void count_nodes_no_return(nodetype *start, int *count) {
    while (start != NULL) {
        (*count)++;
        start = start->next;
    }
}
//search a number and delete every node after that.
nodetype *search_and_delete_rest(nodetype *start, int num) {
    nodetype *p = start;
    while (p->info != num && p->next != NULL)
        p = p->next;
    if (p->info == num) {
        nodetype *temp = NULL;
        while (p->next != NULL) {
            temp = p->next;
            p->next = temp->next;
            free(temp);
        }
    } else
        printf("Number not found.\n");
    return start;
}
//insert a node from left
nodetype *insert_from_left(nodetype *start, int num) {
    nodetype *p = (nodetype *)malloc(sizeof(nodetype));
    p->info = num;
    if (start == NULL)
        p->next = NULL;
    else {
        p->next = start;
    }
    start = p;
    return start;
}

//finding the largest number of all nodes
int largest_number(nodetype *start) {
    int num = 0;
    while (start->next != NULL) {
        if (start->info > num)
            num = start->info;
        start = start->next;
    }
    return num;
}
//splits a list based on the node number input from the user
//k = number of the node from where the list splits
//c = count the node number and for searching k number node
nodetype *split_list(nodetype *start, int k) {
    nodetype *new_list_head;
    int c = 1;
    while (c != k && start->next != NULL) {
        c++;
        start = start->next;
    }
    if (c == k) {
        new_list_head = start->next;
        start->next = NULL;
    }
    return new_list_head;
}

void display_both_lists(nodetype *start, nodetype *new_list_head) {
    while (start != NULL) {
        printf("%d ", start->info);
        start = start->next;
    }
    printf("\n");
    while (new_list_head != NULL) {
        printf("%d ", new_list_head->info);
        new_list_head = new_list_head->next;
    }
    printf("\n");
}
//to print the number stored in the middle node
void middle_node(nodetype *start) {
    int c = 1, k = 1;
    nodetype *middle = start;
    while (start != NULL) {
        c++;
        start = start->next;
    }
    while (k < (c / 2)) {
        middle = middle->next;
        k++;
    }
    if (c % 2 == 0)
        printf("The middle node is %d.\n", middle->info);
    else
        printf("The middle nodes are %d and %d.\n", middle->info, middle->next->info);
}

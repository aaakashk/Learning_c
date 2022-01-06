#include <stdio.h>
#define MAX_SIZE 100

void bubble_sort(int[], int);

int main() {
    int array[MAX_SIZE], n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    printf("Enter the elements of array: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &array[i]);
    bubble_sort(array, n);
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
}

void bubble_sort(int arr[], int n) {
    int i, j, temp = 0;
    for (int i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

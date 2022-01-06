#include <stdio.h>
#define MAX_SIZE 100

void selection_sort(int[], int);

int main() {
    int array[MAX_SIZE], n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    printf("Enter the elements of array: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &array[i]);
    selection_sort(array, n);
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
}

void selection_sort(int arr[], int n) {
    int i, j, pos = 0, min = 0;
    for (int i = 0; i < n; i++) {
        min = arr[i];
        pos = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < min) {
                min = arr[j];
                pos = j;
            }
        }
        if (pos != i) {
            arr[pos] = arr[i];
            arr[i] = min;
        }
    }
}
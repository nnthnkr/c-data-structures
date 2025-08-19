#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int num_of_elements(int arr[], int n);
void display(int arr[], int n);

int main(void) {
    int arr[MAX] = {1, 2, 1, 4, 3, 5, 6, 9, 4, 5, 9, 3, 3};
    int elem_to_insert = 69, insert_at_position = 0;
   
    printf("\n%d\n", num_of_elements(arr, MAX));
    display(arr, num_of_elements(arr, MAX));

    printf("Enter element to insert and its valid position(0-%d): ", num_of_elements(arr, MAX));
    scanf("%d %d", &elem_to_insert, &insert_at_position);

    // move all elements starting the last element till the element at position "insert_at_position" to the right
    for (int i = num_of_elements(arr, MAX) + 1; i > insert_at_position; i--)
        arr[i] == arr[i-1];
    arr[insert_at_position] = elem_to_insert;

    printf("\nAfter inserting %d at %d in arr.\n", elem_to_insert, insert_at_position);
    display(arr, num_of_elements(arr, MAX));

    return 0;
}

int num_of_elements(int arr[], int n) {
    int i = 0;
    while (i < n && arr[i++] != 0);
    return i-1;       // i by itself is 1-based index of the element.
}

void display(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

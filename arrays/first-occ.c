#include <stdio.h>

// returns -1 if elem(ent) is not found
// returns elem(ent) index otherwise
int first_occurrence(int arr[], size_t n, int elem);

int main(void) {
    int arr[] = {2, 1, 4, 5, 3, 4, 7, 5, 8, 9, 12, 43, 2};
    size_t n = sizeof(arr) / sizeof(arr[0]);
    
    int elem = 7;
    int idx = first_occurrence(arr, n, elem);
    
    printf("First occurrence of %d is at position %d", elem, idx+1);

    return 0;
}

int first_occurrence(int arr[], size_t n, int elem) {
    for (int i = 0; i < n; ++i) {
        if (arr[i] == elem)
            return i;
    }
    return -1;
}

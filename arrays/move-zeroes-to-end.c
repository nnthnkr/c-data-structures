#include <stdio.h>

unsigned int
move_zeroes_to_end(int *arr, unsigned int n);

int main(void) {
    // maintaining the order is not necessary
    int arr[] = {0, 1};
    unsigned int n = sizeof(arr) / sizeof(arr[0]);
    
    unsigned int pos = move_zeroes_to_end(arr, n);

    for (int i = 0; i < n; ++i) {
        printf(" %d ", arr[i]);
    }
    
    // pos = index of last non-zero element + 1
    printf("\nPosition of last non zero elem: %d\n", pos);

    return 0;
}

unsigned int
move_zeroes_to_end(int *arr, unsigned int n) {

    unsigned int i = 0, j = n - 1;
    int tmp;
    while (i < j) {
        if (arr[i] == 0) {
            while (j > i && arr[j] == 0) j--;
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            continue;
        }
        i++;
    }

    return i;
}


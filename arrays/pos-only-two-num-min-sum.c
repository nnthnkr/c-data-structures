#include <stdio.h>

typedef unsigned int uint;

void two_num_min_sum(int arr[], uint n) {
    if (n <= 1) {
        fprintf(stderr, "[ERROR]: Expected array with atleast 2 elements.");
        return;
    } 
    if (n == 2) {    
        printf("Two numbers with sum closest to 0: %d and %d.\n", arr[0], arr[1]);
        return;
    }

    int idx_of_minA = 0, 
        minA        = arr[idx_of_minA],
        minB        = arr[0]; 
    
    // Loop to find 1st smallest number
    for (int i = 1; i < n; ++i) {
        if (arr[i] < minA) {
            minA        = arr[i];
            idx_of_minA = i;
        }
    }

    // Loop to find 2nd smallest number
    for (int i = 0; i < n; ++i) {
        if (i == idx_of_minA)   continue;
        if (minA <= arr[i] && arr[i] <= minB)
            minB = arr[i];
    }

    printf("Two numbers with sum closest to 0: %d and %d.\n", minA, minB); 
}

int main(void) {
    int arr[] = {1, 1, 2, 1, 34, 3, 23, 9};
    uint n = sizeof(arr) / sizeof(arr[0]);
    
    two_num_min_sum(arr, n);

    return 0;
}

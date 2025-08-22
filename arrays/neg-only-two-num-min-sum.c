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

    int idx_of_maxA = 0, 
        maxA        = arr[idx_of_maxA],
        maxB        = arr[0]; 
    
    // Loop to find 1st largest (negative) number
    for (int i = 1; i < n; ++i) {
        if (arr[i] > maxA) {
            maxA	= arr[i];
            idx_of_maxA = i;
        }
    }

    // Loop to find 2nd largest (negative) number
    for (int i = 0; i < n; ++i) {
        if (i == idx_of_maxA)   continue;
        if (maxA >= arr[i] && arr[i] >= maxB)
            maxB = arr[i];
    }

    printf("Two numbers with sum closest to 0: %d and %d.\n", maxA, maxB); 
}

int main(void) {
    int arr[] = {-1, -5, -3, -6, -4, -6, -2, -1};
    uint n = sizeof(arr) / sizeof(arr[0]);
    
    two_num_min_sum(arr, n);

    return 0;
}

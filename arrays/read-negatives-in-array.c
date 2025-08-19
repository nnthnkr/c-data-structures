#include <stdio.h>

int main(void) {
    int arr[] = { -1, -3, 5, -7, 9, -11, -13 };
    short sz = sizeof arr / sizeof arr[0];
    
    int i = -1, neg = 0;
    while (i++ < sz) { (arr[i] < 0) ? (neg++) : 0; } 

    printf("Number of negatives: %d\n", neg);

    return 0;
}

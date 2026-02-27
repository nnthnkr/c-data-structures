// 1. RF to input and add n numbers
// Example:
//  add(5)
//      Enter num: __
//      Enter num: __
//      ..
//      Enter num: __
//      Sum is: __

#include <stdio.h>

void add(int n);
void add_(int n, int num, int sum);

int main() {
    int n = 0;

    printf("How many numbers do you want to add: ");
    scanf("%d", &n);
    
    add(n);

    return 0;
}

void add(int n) {
    add_(n, 0, 0);
};

void add_(int n, int num, int sum) {
    if (n <= 0) { 
        printf("Sum is: %d\n", sum);
        return;
    } 
    printf("Enter num: ", n);
    scanf("%d", &num);

    add_(n-1, num, num+sum);
}

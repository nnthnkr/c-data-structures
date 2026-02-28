// 4. RF to display all _proper divisors_ of a number and display their sum.
// Example:
//  proper_divisors_sum(45)
//      1 3 5 9 15
//      sum = 33

#include <stdio.h>

int proper_divisors_sum(int num);
int f(int num, int cur_num, int sum);

int main(void) {
    int sum; 
    proper_divisors_sum(6);
    proper_divisors_sum(13);
    proper_divisors_sum(28);
    proper_divisors_sum(36);
    proper_divisors_sum(2);
    proper_divisors_sum(100);
    proper_divisors_sum(1);
    proper_divisors_sum(49);
    proper_divisors_sum(120);

    return 0;
}

int proper_divisors_sum(int num) {
    return f(num, 1, 0);
}

int f(int num, int cur_num, int sum) {

    if (2 * cur_num > num) { 
        printf("\nSum: %d\n", sum); 
        return 0; 
    }
    
    int is_divisor = 0;          // 1 when cur_num is divisor of num
    if (num % cur_num == 0) { 
        printf("%d ", cur_num);
        is_divisor = 1;
    }
    return f(num, cur_num + 1, sum + cur_num * is_divisor);
}

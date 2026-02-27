// 3. RF to count all prime numbers between two positive integers `a` and `b` (inclusive).
// Example:
//  primes_between(7, 23)
//      7, 11, 13, 17, 19, 23

#include <stdio.h>

void primes_between(int, int);
int check_prime(int);


int check_prime_helper(int, int);

int main(void) {

    primes_between(1, 10);

    putchar('\n');
    return 0;
}

void primes_between(int a, int b) {
    // base condition
    if (a > b) { return; }

    if (check_prime(a)) { printf("%d ", a); }
    
    primes_between(a + 1, b);   // tail recursion
}

/*
int check_prime(int n) {
    int i = 2;
    while (i * i <= n) {
        if (n % i == 0) { return 0; }
        i++;
    }
    return 1;
}*/

// recursive check_prime
int check_prime(int n) {
    return check_prime_helper(n, 2);
}

int check_prime_helper(int n, int i) {
    if (i * i > n) { 
        return 1; 
    } else if (n % i == 0) { 
        return 0; 
    }
    
    check_prime_helper(n, i + 1); 
}

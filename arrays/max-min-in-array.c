#include <stdio.h>

void minmax(short arr[], short n, short *max, short *min);

short main(void) {
    short arr[] = {-2, 1, 4, 3, 2, 6, 4, 7, 6, 8, -1, 3, 4, 9, 3, 4, 3, 4, 2, 10};
    short n     = sizeof arr / sizeof arr[0];

    short max = 0, min = 0;

    minmax(arr, n, &max, &min);

    printf("Maximum: %d\n", max);
    printf("Minimum: %d\n", min);

    return 0;
}

void minmax(short arr[], short n, short *max, short *min) {
    *max = arr[0];
    *min = arr[0];

    short i = 0;
    while ( i < n ) {
        if ( arr[i] > *max )
            *max = arr[i];
        else if ( arr[i] < *min )
            *min = arr[i];
        i++;
    }
}

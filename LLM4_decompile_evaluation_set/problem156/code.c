#include <stdio.h>
#include <stdlib.h>

void func0(int num, int *result) {
    int even_count = 0, odd_count = 0;
    num = abs(num);
    
    do {
        int digit = num % 10;
        if (digit % 2 == 0) {
            even_count++;
        } else {
            odd_count++;
        }
        num /= 10;
    } while (num > 0);

    result[0] = even_count;
    result[1] = odd_count;
}

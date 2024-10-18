#include <stdio.h>

int func0(int n) {
    int prod = 1, has_odd = 0, digit;
    while (n > 0) {
        digit = n % 10;
        if (digit % 2 == 1) {
            has_odd = 1;
            prod *= digit;
        }
        n /= 10;
    }
    return has_odd ? prod : 0;
}

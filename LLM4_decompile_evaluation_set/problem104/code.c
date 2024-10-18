#include <stdio.h>
#include <stdlib.h>

char* func0(int n, int m) {
    if (n > m) return "-1";
    int num = (m + n) / 2;
    char* out = (char*)malloc(33);
    out[0] = '\0';

    int index = 32;
    out[index--] = '\0';

    do {
        out[index--] = '0' + num % 2;
        num /= 2;
    } while (num > 0);

    return &out[index + 1]; 
}

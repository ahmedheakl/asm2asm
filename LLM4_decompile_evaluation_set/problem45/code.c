#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void func0(int x, int base, char *out) {
    int index = 0;
    char temp[33];
    while (x > 0) {
        temp[index++] = (x % base) + '0';
        x = x / base;
    }
    int j = 0;
    while(index > 0) {
        out[j++] = temp[--index];
    }
    out[j] = '\0';
}

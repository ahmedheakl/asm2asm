#include <stdio.h>
#include <string.h>

void func0(int number, char *result) {
    const char *rep[] = {"m", "cm", "d", "cd", "c", "xc", "l", "xl", "x", "ix", "v", "iv", "i"};
    const int num[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    int pos = 0;
    result[0] = '\0';

    while(number > 0) {
        while (number >= num[pos]) {
            strcat(result, rep[pos]);
            number -= num[pos];
        }
        if (number > 0) pos++;
    }
}

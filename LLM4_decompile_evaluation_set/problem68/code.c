#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int func0(const char *s, int n) {
    char num1[10] = "";
    char num2[10] = "";
    int is12 = 0, j = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (isdigit(s[i])) {
            if (is12 == 0) {
                num1[j++] = s[i];
            } else {
                num2[j++] = s[i];
            }
        } else {
            if (is12 == 0 && j > 0) {
                is12 = 1;
                j = 0;
            }
        }
    }
    return n - atoi(num1) - atoi(num2);
}

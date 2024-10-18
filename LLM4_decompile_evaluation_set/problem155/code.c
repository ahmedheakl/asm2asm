#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool func0(const char *a, const char *b) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    char *temp = (char *)malloc(2 * len_b + 1);

    for (int i = 0; i < len_b; i++) {
        strncpy(temp, b + i, len_b - i);
        strncpy(temp + len_b - i, b, i);
        temp[len_b] = '\0';
        if (strstr(a, temp)) {
            free(temp);
            return true;
        }
    }

    free(temp);
    return false;
}

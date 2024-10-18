#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *func0(const char *str) {
    int len = strlen(str), i, j;
    char *result = (char *)malloc(2 * len + 1);
    if (!result) {
        return NULL; 
    }

    for (i = 0; i < len; i++) {
        int is_palindrome = 1;
        for (j = 0; j < (len - i) / 2; j++) {
            if (str[i + j] != str[len - 1 - j]) {
                is_palindrome = 0;
                break;
            }
        }
        if (is_palindrome) {
            strncpy(result, str, len);
            for (j = 0; j < i; j++) {
                result[len + j] = str[i - j - 1];
            }
            result[len + i] = '\0';
            return result;
        }
    }

    strncpy(result, str, len);
    for (j = 0; j < len; j++) {
        result[len + j] = str[len - j - 1];
    }
    result[2 * len] = '\0';
    return result;
}

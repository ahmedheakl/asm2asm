#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int func0(char* dict[][2], int size) {
    if (size == 0) return 0;
    int has_lower = 0, has_upper = 0;
    for (int i = 0; i < size; ++i) {
        char* key = dict[i][0];
        for (int j = 0; key[j]; ++j) {
            if (!isalpha((unsigned char)key[j])) return 0;
            if (isupper((unsigned char)key[j])) has_upper = 1;
            if (islower((unsigned char)key[j])) has_lower = 1;
            if (has_upper + has_lower == 2) return 0;
        }
    }
    return 1;
}

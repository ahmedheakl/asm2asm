#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **func0(const char *str, int *count) {
    int len = strlen(str);
    char **out = malloc(len * sizeof(char *));
    
    char *current = malloc(len + 1);
    current[0] = '\0';

    for (int i = 0; i < len; ++i) {
        size_t current_len = strlen(current);
        current = realloc(current, current_len + 2);
        current[current_len] = str[i];
        current[current_len + 1] = '\0';

        out[i] = malloc(strlen(current) + 1);
        strcpy(out[i], current);
    }
    free(current);
    
    *count = len;
    return out;
}

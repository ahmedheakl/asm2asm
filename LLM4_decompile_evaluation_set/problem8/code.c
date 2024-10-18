#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **func0(char **strings, int size, const char *substring, int *out_size) {
    char **out = NULL;
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (strstr(strings[i], substring) != NULL) {
            out = (char **)realloc(out, sizeof(char *) * (count + 1));
            out[count] = strings[i];
            count++;
        }
    }
    *out_size = count;
    return out;
}
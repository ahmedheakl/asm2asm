#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int func0(char** strings, int count, const char* prefix, char*** out) {
    int prefix_length = strlen(prefix);
    *out = (char**)malloc(count * sizeof(char*));
    int out_count = 0;

    for (int i = 0; i < count; i++) {
        if (strncmp(strings[i], prefix, prefix_length) == 0) {
            (*out)[out_count++] = strings[i];
        }
    }

    return out_count;
}

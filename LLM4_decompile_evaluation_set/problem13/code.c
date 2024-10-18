#include <stdio.h>
#include <string.h>

char *func0(char **strings, int count) {
    char *out = "";
    int longest_length = 0;
    for (int i = 0; i < count; i++) {
        int current_length = strlen(strings[i]);
        if (current_length > longest_length) {
            out = strings[i];
            longest_length = current_length;
        }
    }
    return out;
}

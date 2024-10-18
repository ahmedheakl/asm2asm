#include <stdio.h>
#include <string.h>

void func0(const char *text, char *out) {
    int space_len = 0;
    int j = 0;
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == ' ') {
            space_len++;
        } else {
            if (space_len == 1) out[j++] = '_';
            if (space_len == 2) out[j++] = '_', out[j++] = '_';
            if (space_len > 2) out[j++] = '-';
            space_len = 0;
            out[j++] = text[i];
        }
    }
    if (space_len == 1) out[j++] = '_';
    if (space_len == 2) out[j++] = '_', out[j++] = '_';
    if (space_len > 2) out[j++] = '-';
    out[j] = '\0';
}

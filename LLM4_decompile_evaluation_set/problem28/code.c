#include <stdio.h>
#include <string.h>

void func0(const char* str, char* out) {
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        char w = str[i];
        if (w >= 'a' && w <= 'z') {
            w -= 32;
        } else if (w >= 'A' && w <= 'Z') {
            w += 32;
        }
        out[i] = w;
    }
    out[length] = '\0';
}

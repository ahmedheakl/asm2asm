#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool func0(const char *text) {
    int len = strlen(text);
    for (int i = 0; i < len / 2; i++) {
        if (text[i] != text[len - 1 - i]) {
            return false;
        }
    }
    return true;
}

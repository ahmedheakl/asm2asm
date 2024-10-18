#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool func0(const char* str) {
    int l = strlen(str);
    if (l < 2) return false;
    for (int i = 2; i * i <= l; i++) {
        if (l % i == 0) return false;
    }
    return true;
}

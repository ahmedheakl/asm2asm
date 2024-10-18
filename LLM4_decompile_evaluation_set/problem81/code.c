#include <string.h>
#include <stdbool.h>

bool func0(const char* s) {
    if (strlen(s) < 3) return false;
    for (int i = 2; i < strlen(s); i++)
        if (s[i] == s[i-1] || s[i] == s[i-2]) return false;
    return true;
}

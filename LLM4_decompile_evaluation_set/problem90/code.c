#include <stdio.h>
#include <string.h>

void func0(const char *s, char *out) {
    int i;
    for (i = 0; s[i] != '\0'; i++) {
        int w = ((int)s[i] - 'a' + 4) % 26 + 'a';
        out[i] = (char)w;
    }
    out[i] = '\0';
}

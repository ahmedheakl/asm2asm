#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void func0(char *s, int encode) {
    int shift = encode ? 5 : 21;
    size_t len = strlen(s);
    for (size_t i = 0; i < len; i++) {
        int w = ((s[i] - 'a' + shift) % 26) + 'a';
        s[i] = (char)w;
    }
}

#include <stdio.h>
#include <string.h>

int func0(const char *s) {
    const char *uvowel = "AEIOU";
    int count = 0;
    for (int i = 0; s[i] != '\0' && i * 2 < strlen(s); i++) {
        if (strchr(uvowel, s[i * 2]) != NULL) {
            count += 1;
        }
    }
    return count;
}

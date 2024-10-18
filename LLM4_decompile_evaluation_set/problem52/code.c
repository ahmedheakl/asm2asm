#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void func0(char *text) {
    const char *vowels = "AEIOUaeiou";
    char *out = text;
    while (*text != '\0') {
        if (strchr(vowels, *text) == NULL) {
            *out++ = *text;
        }
        text++;
    }
    *out = '\0';
}

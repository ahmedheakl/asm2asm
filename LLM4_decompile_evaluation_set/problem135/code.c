#include <stdio.h>
#include <string.h>
#include <ctype.h>

int func0(const char *txt) {
    int len = strlen(txt);
    if (len == 0) return 0;
    char last_char = txt[len - 1];
    if (!isalpha((unsigned char)last_char)) return 0;
    if (len == 1) return 1;
    char second_last_char = txt[len - 2];
    if (isalpha((unsigned char)second_last_char)) return 0;
    return 1;
}

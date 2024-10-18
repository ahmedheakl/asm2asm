#include <stdio.h>
#include <string.h>

int func0(const char *str, const char *substring) {
    int out = 0;
    int str_len = strlen(str);
    int sub_len = strlen(substring);
    if (str_len == 0) return 0;
    for (int i = 0; i <= str_len - sub_len; i++) {
        if (strncmp(&str[i], substring, sub_len) == 0)
            out++;
    }
    return out;
}

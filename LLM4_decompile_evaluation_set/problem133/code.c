#include <stdio.h>
#include <string.h>

int func0(const char *str) {
    int count = 0, maxcount = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '[') count += 1;
        if (str[i] == ']') count -= 1;
        if (count < 0) count = 0;
        if (count > maxcount) maxcount = count;
        if (count <= maxcount - 2) return 1;
    }
    return 0;
}

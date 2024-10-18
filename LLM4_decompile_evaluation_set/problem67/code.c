#include <stdio.h>
#include <string.h>

int func0(const char *s) {
    int sum = 0;
    for (int i = 0; s[i] != '\0'; i++)
        if (s[i] >= 'A' && s[i] <= 'Z')
            sum += s[i];
    return sum;
}

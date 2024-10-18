#include <stdio.h>
#include <string.h>

void func0(char *s, int encode) {
    int l = strlen(s);
    int num = (l + 2) / 3;
    char x[4];

    for (int i = 0; i < num; ++i) {
        int len = (i * 3 + 3 <= l) ? 3 : l - i * 3;
        strncpy(x, s + i * 3, len);
        x[len] = '\0';

        if (len == 3) {
            if (encode) {
                char temp = x[2];
                x[2] = x[1];
                x[1] = x[0];
                x[0] = temp;
            } else {
                char temp = x[0];
                x[0] = x[1];
                x[1] = x[2];
                x[2] = temp;
            }
        }
        strncpy(s + i * 3, x, len);
    }
}

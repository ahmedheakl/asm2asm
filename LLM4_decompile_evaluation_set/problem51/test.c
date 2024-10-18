#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>
void func0(char *s, int encode);

int main() {
    srand((unsigned int)time(NULL));

    for (int i = 0; i < 100; i++) {
        int l = 10 + rand() % 11;
        char *str = (char *)malloc(l + 1);
        for (int j = 0; j < l; j++) {
            char chr = 'a' + rand() % 26;
            str[j] = chr;
        }
        str[l] = '\0';

        char *encoded_str = (char *)malloc(l + 1);
        strcpy(encoded_str, str);
        func0(encoded_str, 1);
        func0(encoded_str, 0);
        assert(strcmp(encoded_str, str) == 0);

        free(str);
        free(encoded_str);
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void func0(const char *s, const char *c, char *result, char *palindrome) {
    int len = strlen(s);
    char *n = malloc((len + 1) * sizeof(char));
    int ni = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        const char *temp = c;
        bool found = false;
        while (*temp != '\0') {
            if (s[i] == *temp) {
                found = true;
                break;
            }
            temp++;
        }
        if (!found) {
            n[ni++] = s[i];
        }
    }
    n[ni] = '\0';

    int n_len = strlen(n);
    bool is_palindrome = true;
    for (int i = 0; i < n_len / 2; i++) {
        if (n[i] != n[n_len - 1 - i]) {
            is_palindrome = false;
            break;
        }
    }

    strcpy(result, n);
    strcpy(palindrome, is_palindrome ? "True" : "False");

    free(n);
}

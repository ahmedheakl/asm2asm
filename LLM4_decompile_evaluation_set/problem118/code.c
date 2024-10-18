#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char **func0(const char *s, int n, int *returnSize) {
    const char *vowels = "aeiouAEIOU";
    char **out = NULL;
    int numc = 0, word_count = 0, begin = 0;
    size_t length = strlen(s);
    char *current = (char *)malloc(length + 1);

    for (int i = 0; i <= length; i++) {
        if (isspace(s[i]) || s[i] == '\0') {
            if (numc == n) {
                current[i - begin] = '\0';
                out = (char **)realloc(out, sizeof(char *) * (word_count + 1));
                out[word_count] = (char *)malloc(strlen(current) + 1);
                strcpy(out[word_count], current);
                word_count++;
            }
            begin = i + 1;
            numc = 0;
        } else {
            current[i - begin] = s[i];
            if (strchr(vowels, s[i]) == NULL && isalpha((unsigned char)s[i])) {
                numc++;
            }
        }
    }
    free(current);

    *returnSize = word_count;
    return out;
}

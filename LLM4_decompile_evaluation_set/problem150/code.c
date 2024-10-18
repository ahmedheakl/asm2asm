#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** func0(char **lst, int lst_size, int *return_size) {
    int i, j;
    char *temp;

    *return_size = 0;
    for (i = 0; i < lst_size; ++i) {
        if (strlen(lst[i]) % 2 == 0) {
            lst[*return_size] = lst[i];
            (*return_size)++;
        }
    }

    for (i = 0; i < *return_size - 1; ++i) {
        for (j = 0; j < *return_size - i - 1; ++j) {
            size_t len_j = strlen(lst[j]);
            size_t len_j1 = strlen(lst[j + 1]);
            if (len_j > len_j1 || (len_j == len_j1 && strcmp(lst[j], lst[j + 1]) > 0)) {
                temp = lst[j];
                lst[j] = lst[j + 1];
                lst[j + 1] = temp;
            }
        }
    }

    char **out = malloc(*return_size * sizeof(char *));
    for (i = 0; i < *return_size; ++i) {
        out[i] = lst[i];
    }

    return out;
}

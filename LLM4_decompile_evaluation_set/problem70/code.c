#include <stdio.h>
#include <stdlib.h>

int func0(int *lst, int size) {
    int *freq = (int *)calloc(size + 1, sizeof(int));
    int max = -1;

    for (int i = 0; i < size; i++) {
        freq[lst[i]]++;
        if ((freq[lst[i]] >= lst[i]) && (lst[i] > max)) {
            max = lst[i];
        }
    }

    free(freq);
    return max;
}

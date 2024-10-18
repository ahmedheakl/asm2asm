#include <stdio.h>
#include <stdlib.h>

void func0(int *lst, int size, int *out) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (lst[i] > lst[j]) {
                int temp = lst[i];
                lst[i] = lst[j];
                lst[j] = temp;
            }
        }
    }

    int l = 0, r = size - 1;
    int index = 0;

    while (l <= r) {
        if (l == r) {
            out[index++] = lst[l++];
        } else {
            out[index++] = lst[l++];
            out[index++] = lst[r--];
        }
    }
}

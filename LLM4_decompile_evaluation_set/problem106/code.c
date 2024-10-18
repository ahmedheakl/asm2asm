#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void func0(int *arr, int size, char ***out, int *out_size) {
    char *names[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    int i, j;

    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    *out_size = 0;
    for (i = size - 1; i >= 0; i--) {
        if (arr[i] >= 1 && arr[i] <= 9) {
            (*out_size)++;
        }
    }

    *out = malloc(*out_size * sizeof(char *));

    for (i = size - 1, j = 0; i >= 0 && j < *out_size; i--) {
        if (arr[i] >= 1 && arr[i] <= 9) {
            (*out)[j++] = names[arr[i]];
        }
    }
}

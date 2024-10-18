#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void func0(int *x, int size, int **out, int *out_size) {
    *out = malloc(size * sizeof(int));
    *out_size = 0;

    for (int i = 0; i < size; i++) {
        int num = x[i];
        bool has_even_digit = false;
        if (num == 0) has_even_digit = true;

        while (num > 0 && !has_even_digit) {
            if (num % 2 == 0) has_even_digit = true;
            num = num / 10;
        }

        if (!has_even_digit) {
            (*out)[*out_size] = x[i];
            (*out_size)++;
        }
    }

    for (int i = 0; i < *out_size - 1; i++) {
        for (int j = 0; j < *out_size - i - 1; j++) {
            if ((*out)[j] > (*out)[j + 1]) {
                int temp = (*out)[j];
                (*out)[j] = (*out)[j + 1];
                (*out)[j + 1] = temp;
            }
        }
    }
}

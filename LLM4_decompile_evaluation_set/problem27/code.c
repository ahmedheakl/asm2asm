#include <stdio.h>
#include <stdlib.h>

int* func0(int* numbers, int size, int* new_size) {
    int* out = (int*)malloc(size * sizeof(int));
    int* has1 = (int*)calloc(size, sizeof(int));
    int* has2 = (int*)calloc(size, sizeof(int));
    int has1_count = 0;
    int has2_count = 0;
    int out_count = 0;

    for (int i = 0; i < size; i++) {
        int num = numbers[i];
        int in_has2 = 0;

        for (int j = 0; j < has2_count; j++) {
            if (has2[j] == num) {
                in_has2 = 1;
                break;
            }
        }
        if (in_has2) continue;

        int in_has1 = 0;
        for (int j = 0; j < has1_count; j++) {
            if (has1[j] == num) {
                in_has1 = 1;
                break;
            }
        }
        if (in_has1) {
            has2[has2_count++] = num;
        } else {
            has1[has1_count++] = num;
        }
    }

    for (int i = 0; i < size; i++) {
        int num = numbers[i];
        int in_has2 = 0;
        for (int j = 0; j < has2_count; j++) {
            if (has2[j] == num) {
                in_has2 = 1;
                break;
            }
        }
        if (!in_has2) {
            out[out_count++] = num;
        }
    }

    *new_size = out_count;
    free(has1);
    free(has2);
    return out;
}

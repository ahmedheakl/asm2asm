#include <stdio.h>
#include <stdlib.h>

int *func0(int *numbers, int size) {
    if (size <= 0) {
        return NULL;
    }
    
    int *out = malloc(size * sizeof(int));
    if (!out) {
        return NULL;
    }
    
    int max = numbers[0];
    for (int i = 0; i < size; i++) {
        if (numbers[i] > max) max = numbers[i];
        out[i] = max;
    }
    return out;
}

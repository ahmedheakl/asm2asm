#include <stdio.h>
#include <math.h>

void func0(float *numbers, int size) {
    float min = numbers[0], max = numbers[0];
    for (int i = 1; i < size; i++) {
        if (numbers[i] < min) min = numbers[i];
        if (numbers[i] > max) max = numbers[i];
    }
    for (int i = 0; i < size; i++) {
        numbers[i] = (numbers[i] - min) / (max - min);
    }
}

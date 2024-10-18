#include <stdio.h>
#include <math.h>
#include <float.h>

void func0(float numbers[], int size, float out[2]) {
    float min_diff = FLT_MAX;
    int i, j;

    out[0] = numbers[0];
    out[1] = numbers[1];

    for (i = 0; i < size; i++) {
        for (j = i + 1; j < size; j++) {
            float diff = fabs(numbers[i] - numbers[j]);
            if (diff < min_diff) {
                min_diff = diff;
                out[0] = numbers[i];
                out[1] = numbers[j];
            }
        }
    }

    if (out[0] > out[1]) {
        float temp = out[0];
        out[0] = out[1];
        out[1] = temp;
    }
}

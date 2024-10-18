#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float func0(float *l, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (l[i] > l[j]) {
                float temp = l[i];
                l[i] = l[j];
                l[j] = temp;
            }
        }
    }
    if (size % 2 == 1) return l[size / 2];
    return 0.5 * (l[size / 2] + l[size / 2 - 1]);
}

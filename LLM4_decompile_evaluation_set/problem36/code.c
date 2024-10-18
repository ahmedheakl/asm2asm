#include <stdio.h>

float func0(float *l, int size) {
    float max = -10000;
    for (int i = 0; i < size; i++)
        if (max < l[i]) max = l[i];
    return max;
}

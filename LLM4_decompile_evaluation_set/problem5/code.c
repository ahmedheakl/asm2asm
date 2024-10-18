#include <stdio.h>
#include <math.h>

float func0(float numbers[], int size) {
    float sum = 0;
    float avg, msum, mavg;
    int i = 0;

    for (i = 0; i < size; i++)
        sum += numbers[i];

    avg = sum / size;
    msum = 0;

    for (i = 0; i < size; i++)
        msum += fabs(numbers[i] - avg);

    return msum / size;
}

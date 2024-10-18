#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int func0(float numbers[], int size, float threshold) {
    int i, j;

    for (i = 0; i < size; i++)
        for (j = i + 1; j < size; j++)
            if (fabs(numbers[i] - numbers[j]) < threshold)
                return 1;

    return 0;
}

#include <stdio.h>
#include <math.h>

int func0(float *lst, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += (int)ceil(lst[i]) * (int)ceil(lst[i]);
    }
    return sum;
}

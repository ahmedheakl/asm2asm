#include <stdio.h>

int func0(int *arr, int size) {
    int max = -1;
    for (int i = 1; i < size; ++i) {
        if (arr[i] < arr[i - 1]) max = i;
    }
    return max;
}

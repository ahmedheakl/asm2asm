#include <stdio.h>
#include <stdlib.h>

int func0(int *arr, int arr_size) {
    if (arr_size == 0) return -32768;
    int sum = 0, prods = 1, i;
    for (i = 0; i < arr_size; i++) {
        sum += abs(arr[i]);
        if (arr[i] == 0) prods = 0;
        if (arr[i] < 0) prods = -prods;
    }
    return sum * prods;
}

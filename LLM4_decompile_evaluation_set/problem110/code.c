#include <stdio.h>
#include <stdbool.h>

bool func0(int *arr, int size) {
    int num = 0;
    if (size == 0) return true;
    for (int i = 1; i < size; i++)
        if (arr[i] < arr[i - 1]) num += 1;
    if (arr[size - 1] > arr[0]) num += 1;
    if (num < 2) return true;
    return false;
}

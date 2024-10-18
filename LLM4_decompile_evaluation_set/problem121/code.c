#include <stdio.h>
#include <stdlib.h>

void func0(int* arr, int arr_size, int k, int* out) {
    for (int i = 0; i < arr_size - 1; i++) {
        for (int j = 0; j < arr_size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < k; i++) {
        out[i] = arr[arr_size - k + i];
    }
}

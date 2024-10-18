#include <stdio.h>
#include <stdlib.h>

void func0(int *arr, int size) {
    int count_ones, x, y, temp;
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            count_ones = 0;
            x = arr[i];
            y = arr[j];
            while (x > 0) {
                count_ones += x & 1;
                x >>= 1;
            }
            x = count_ones;
            count_ones = 0;
            while (y > 0) {
                count_ones += y & 1;
                y >>= 1;
            }
            y = count_ones;
            if (y < x || (y == x && arr[j] < arr[i])) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

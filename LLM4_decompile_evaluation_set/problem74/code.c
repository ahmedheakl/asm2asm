#include <stdio.h>

int func0(int arr[], int size) {
    int out = 0;
    for (int i = 0; i < size / 2; i++) {
        if (arr[i] != arr[size - 1 - i]) {
            out++;
        }
    }
    return out;
}

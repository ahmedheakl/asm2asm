#include <stdio.h>

void func0(int *numbers, int size, int *result) {
    int sum = 0, product = 1;
    for (int i = 0; i < size; i++) {
        sum += numbers[i];
        product *= numbers[i];
    }
    result[0] = sum;
    result[1] = product;
}

#include <stdio.h>

int func0(int lst[], int size) {
    int largest = 0, sum = 0, num, temp;

    for (int i = 0; i < size; ++i) {
        num = lst[i];
        if (num > 1) {
            int prime = 1;
            for (int j = 2; j * j <= num; ++j) {
                if (num % j == 0) {
                    prime = 0;
                    break;
                }
            }
            if (prime) {
                largest = num > largest ? num : largest;
            }
        }
    }

    while (largest > 0) {
        sum += largest % 10;
        largest /= 10;
    }

    return sum;
}

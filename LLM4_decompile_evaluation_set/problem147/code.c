#include <stdio.h>
#include <stdlib.h>

int func0(int nums[], int size) {
    int num = 0;
    for (int i = 0; i < size; i++) {
        if (nums[i] > 10) {
            int first, last;
            last = nums[i] % 10;
            int n = nums[i];
            while (n >= 10) {
                n /= 10;
            }
            first = n;
            if (first % 2 == 1 && last % 2 == 1) {
                num += 1;
            }
        }
    }
    return num;
}

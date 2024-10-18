#include <stdio.h>

long long func0(long long *nums, int size) {
    long long current = nums[0];
    long long min = nums[0];
    for (int i = 1; i < size; i++) {
        current = current < 0 ? current + nums[i] : nums[i];
        if (current < min) min = current;
    }
    return min;
}

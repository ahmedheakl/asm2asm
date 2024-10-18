#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* func0(int nums[], int size) {
    int* sumdigit = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        char w[12]; // Assuming the integer won't exceed the length of an int in string form.
        sprintf(w, "%d", abs(nums[i]));
        int sum = 0, length = strlen(w);
        for (int j = 1; j < length; j++)
            sum += w[j] - '0';
        if (nums[i] > 0) sum += w[0] - '0';
        else sum -= w[0] - '0';
        sumdigit[i] = sum;
    }
    int m;
    for (int i = 0; i < size; i++)
        for (int j = 1; j < size; j++)
            if (sumdigit[j - 1] > sumdigit[j]) {
                m = sumdigit[j]; sumdigit[j] = sumdigit[j - 1]; sumdigit[j - 1] = m;
                m = nums[j]; nums[j] = nums[j - 1]; nums[j - 1] = m;
            }
    
    free(sumdigit);
    return nums;
}

#include <stdio.h>

int func0(int arr[], int k) {
    int sum = 0;
    for (int i = 0; i < k; i++)
        if (arr[i] >= -99 && arr[i] <= 99)
            sum += arr[i];
    return sum;
}

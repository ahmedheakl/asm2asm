#include <stdio.h>
#include <limits.h>

int *func0(int arr[], int length, int output[2]) {
    int smallestEven = INT_MAX;
    int index = -1;
    
    for (int i = 0; i < length; ++i) {
        if (arr[i] % 2 == 0 && (arr[i] < smallestEven || index == -1)) {
            smallestEven = arr[i];
            index = i;
        }
    }
    
    if (index == -1) {
        return NULL;
    }

    output[0] = smallestEven;
    output[1] = index;
    return output;
}

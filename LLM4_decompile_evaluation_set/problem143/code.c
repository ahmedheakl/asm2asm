#include <stdio.h>

int func0(int* lst, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (i % 3 == 0) sum += lst[i] * lst[i];
        else if (i % 4 == 0) sum += lst[i] * lst[i] * lst[i];
        else sum += lst[i];
    }
    return sum;
}

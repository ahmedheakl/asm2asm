#include <stdio.h>

int func0(int lst[], int size) {
    int sum = 0;
    for (int i = 0; i * 2 + 1 < size; i++)
        if (lst[i * 2 + 1] % 2 == 0) sum += lst[i * 2 + 1];
    return sum;
}

#include <stdio.h>

void func0(const int *lst, int size, int result[2]) {
    int maxneg = 0;
    int minpos = 0;
    for (int i = 0; i < size; i++) {
        if (lst[i] < 0 && (maxneg == 0 || lst[i] > maxneg)) maxneg = lst[i];
        if (lst[i] > 0 && (minpos == 0 || lst[i] < minpos)) minpos = lst[i];
    }
    result[0] = maxneg;
    result[1] = minpos;
}

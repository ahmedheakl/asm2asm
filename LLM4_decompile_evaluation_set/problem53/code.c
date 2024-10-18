#include <stdio.h>
#include <stdbool.h>

bool func0(int *l, int size, int t) {
    for (int i = 0; i < size; i++)
        if (l[i] >= t) return false;
    return true;
}

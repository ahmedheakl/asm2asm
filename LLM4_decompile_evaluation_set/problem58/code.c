#include <stdio.h>
#include <stdbool.h>

bool func0(float *l, int size) {
    int incr, decr;
    incr = decr = 0;
    
    for (int i = 1; i < size; i++) {
        if (l[i] > l[i - 1]) incr = 1;
        if (l[i] < l[i - 1]) decr = 1;
    }
    if (incr + decr == 2) return false;
    return true;
}

#include <stdio.h>
#include <limits.h>

int func0(int *lst, int size) {
    if (size < 2) return -1;

    int first = INT_MAX, second = INT_MAX;
    for (int i = 0; i < size; ++i) {
        if (lst[i] < first) {
            second = first;
            first = lst[i];
        } else if (lst[i] < second && lst[i] != first) {
            second = lst[i];
        }
    }

    if (second == INT_MAX) return -1;
    return second;
}

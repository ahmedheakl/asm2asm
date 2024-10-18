#include <stdio.h>
#include <stdbool.h>

bool func0(const int *lst, int lst_size) {
    if (lst_size == 0) return true;

    for (int i = 1; i < lst_size; i++) {
        if (lst[i] < lst[i - 1]) return false;
        if (i >= 2 && lst[i] == lst[i - 1] && lst[i] == lst[i - 2]) return false;
    }
    return true;
}

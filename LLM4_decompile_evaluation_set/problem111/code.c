#include <stdio.h>

const char* func0(int *lst1, int size1, int *lst2, int size2) {
    int num = 0;
    for (int i = 0; i < size1; i++)
        if (lst1[i] % 2 == 0) num += 1;
    for (int i = 0; i < size2; i++)
        if (lst2[i] % 2 == 0) num += 1;
    if (num >= size1) return "YES";
    return "NO";
}

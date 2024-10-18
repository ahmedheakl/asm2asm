#include <stdio.h>

int func0(int operations[], int size) {
    int num = 0;
    for (int i = 0; i < size; i++) {
        num += operations[i];
        if (num < 0) return 1;
    }
    return 0;
}

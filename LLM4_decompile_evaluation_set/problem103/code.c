#include <stdio.h>

int func0(int x, int y) {
    if (y < x) return -1;
    if (y == x && y % 2 == 1) return -1;
    if (y % 2 == 1) return y - 1;
    return y;
}

#include <stdio.h>

void func0(int number, int need, int remaining, int result[2]) {
    if (need > remaining) {
        result[0] = number + remaining;
        result[1] = 0;
    } else {
        result[0] = number + need;
        result[1] = remaining - need;
    }
}

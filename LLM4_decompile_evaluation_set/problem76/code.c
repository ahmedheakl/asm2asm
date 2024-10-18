#include <stdio.h>
#include <stdlib.h>

int func0(int a) {
    if (a < 2) return 0;
    int num = 0;
    for (int i = 2; i * i <= a; i++) {
        while (a % i == 0) {
            a = a / i;
            num++;
        }
    }
    if (a > 1) num++;
    return num == 3;
}

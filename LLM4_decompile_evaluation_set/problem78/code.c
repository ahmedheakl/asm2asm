#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int func0(int a) {
    for (int i = 0; i * i * i <= abs(a); i++)
        if (i * i * i == abs(a)) return 1;
    return 0;
}

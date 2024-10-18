#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int func0(const char *value) {
    double w;
    w = atof(value);
    return (int)(w < 0 ? ceil(w - 0.5) : floor(w + 0.5));
}

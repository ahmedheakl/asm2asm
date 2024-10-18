#include <stdio.h>
#include <stdlib.h>

int func0(const char* x, const char* n){
    int a, b, c, d, i, j;
    char num[101], den[101];

    for (i = 0; x[i] != '/'; i++) {
        num[i] = x[i];
    }
    num[i] = '\0';
    a = atoi(num);

    for (j = 0, i = i + 1; x[i] != '\0'; i++, j++) {
        den[j] = x[i];
    }
    den[j] = '\0';
    b = atoi(den);

    for (i = 0; n[i] != '/'; i++) {
        num[i] = n[i];
    }
    num[i] = '\0';
    c = atoi(num);

    for (j = 0, i = i + 1; n[i] != '\0'; i++, j++) {
        den[j] = n[i];
    }
    den[j] = '\0';
    d = atoi(den);

    if ((a * c) % (b * d) == 0) return 1;
    return 0;
}

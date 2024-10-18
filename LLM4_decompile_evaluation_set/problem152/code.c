#include <stdio.h>
#include <math.h>

long long func0(float lst[], int lst_size) {
    long long sum = 0;
    for (int i = 0; i < lst_size; i++) {
        if (fabs(lst[i] - round(lst[i])) < 1e-4) {
            if (lst[i] > 0 && (int)(round(lst[i])) % 2 == 1) {
                sum += (int)(round(lst[i])) * (int)(round(lst[i]));
            }
        }
    }
    return sum;
}

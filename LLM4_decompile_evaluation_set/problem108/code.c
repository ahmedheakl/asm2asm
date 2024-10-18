#include <stdio.h>
#include <stdlib.h>

int* func0(int n) {
    int* counts = (int*)malloc(2 * sizeof(int));
    counts[0] = 0;
    counts[1] = 0;

    for (int i = 1; i <= n; i++) {
        int reversed = 0, original = i;

        int number = i;
        while (number != 0) {
            reversed = reversed * 10 + number % 10;
            number /= 10;
        }

        if (original == reversed) {
            if (original % 2 == 0) counts[0]++;
            else counts[1]++;
        }
    }

    return counts;
}

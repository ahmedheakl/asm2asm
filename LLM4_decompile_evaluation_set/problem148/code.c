#include <stdio.h>
#include <stdlib.h>

int func0(int n) {
    int *a = (int *)malloc(n * sizeof(int));
    int **sum = (int **)malloc((n + 1) * sizeof(int *));
    int **sum2 = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++) {
        sum[i] = (int *)calloc(3, sizeof(int));
        sum2[i] = (int *)calloc(3, sizeof(int));
    }
    sum[0][0] = sum[0][1] = sum[0][2] = 0;
    sum2[0][0] = sum2[0][1] = sum2[0][2] = 0;
    for (int i = 1; i <= n; i++) {
        a[i - 1] = (i * i - i + 1) % 3;
        for (int j = 0; j < 3; j++) {
            sum[i][j] = sum[i - 1][j];
        }
        sum[i][a[i - 1]] += 1;
    }
    for (int times = 1; times < 3; times++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 3; j++) {
                sum2[i][j] = sum2[i - 1][j];
            }
            if (i >= 1) {
                for (int j = 0; j <= 2; j++) {
                    sum2[i][(a[i - 1] + j) % 3] += sum[i - 1][j];
                }
            }
        }
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < 3; j++) {
                sum[i][j] = sum2[i][j];
                sum2[i][j] = 0;
            }
        }
    }

    int result = sum[n][0];
    for (int i = 0; i <= n; ++i) {
        free(sum[i]);
        free(sum2[i]);
    }
    free(sum);
    free(sum2);
    free(a);
    return result;
}

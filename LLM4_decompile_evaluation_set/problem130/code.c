#include <stdio.h>
#include <stdlib.h>

int *func0(int **grid, int N, int k, int *returnSize) {
    int i, j, x, y, min;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            if (grid[i][j] == 1) {
                x = i;
                y = j;
            }
    min = N * N;
    if (x > 0 && grid[x - 1][y] < min) min = grid[x - 1][y];
    if (x < N - 1 && grid[x + 1][y] < min) min = grid[x + 1][y];
    if (y > 0 && grid[x][y - 1] < min) min = grid[x][y - 1];
    if (y < N - 1 && grid[x][y + 1] < min) min = grid[x][y + 1];
    
    *returnSize = k;
    int *out = (int *)malloc(k * sizeof(int));
    for (i = 0; i < k; i++)
        if (i % 2 == 0) out[i] = 1;
        else out[i] = min;
    return out;
}

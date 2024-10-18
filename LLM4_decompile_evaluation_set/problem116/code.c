#include <stdio.h>
int func0(int **grid, int rows, int cols, int capacity) {
    int out = 0;
    for (int i = 0; i < rows; i++) {
        int sum = 0;
        for (int j = 0; j < cols; j++)
            sum += grid[i][j];
        if (sum > 0) out += (sum + capacity - 1) / capacity;
    }
    return out;
}

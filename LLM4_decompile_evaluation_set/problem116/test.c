#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
int func0(int **grid, int rows, int cols, int capacity);

int main() {
    int rows, cols, capacity;
    int **grid;
    
    // Test case 1
    rows = 3; cols = 4; capacity = 1;
    grid = (int **)malloc(rows * sizeof(int *));
    int grid1_data[3][4] = {{0,0,1,0}, {0,1,0,0}, {1,1,1,1}};
    for (int i = 0; i < rows; i++) {
        grid[i] = (int *)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            grid[i][j] = grid1_data[i][j];
        }
    }
    assert(func0(grid, rows, cols, capacity) == 6);
    for (int i = 0; i < rows; i++) free(grid[i]);
    free(grid);

    // Test case 2
    rows = 4; cols = 4; capacity = 2;
    grid = (int **)malloc(rows * sizeof(int *));
    int grid2_data[4][4] = {{0,0,1,1}, {0,0,0,0}, {1,1,1,1}, {0,1,1,1}};
    for (int i = 0; i < rows; i++) {
        grid[i] = (int *)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            grid[i][j] = grid2_data[i][j];
        }
    }
    assert(func0(grid, rows, cols, capacity) == 5);
    for (int i = 0; i < rows; i++) free(grid[i]);
    free(grid);

    // Test case 3
    rows = 2; cols = 3; capacity = 5;
    grid = (int **)malloc(rows * sizeof(int *));
    int grid3_data[2][3] = {{0,0,0}, {0,0,0}};
    for (int i = 0; i < rows; i++) {
        grid[i] = (int *)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            grid[i][j] = grid3_data[i][j];
        }
    }
    assert(func0(grid, rows, cols, capacity) == 0);
    for (int i = 0; i < rows; i++) free(grid[i]);
    free(grid);

    // Test case 4
    rows = 2; cols = 4; capacity = 2;
    grid = (int **)malloc(rows * sizeof(int *));
    int grid4_data[2][4] = {{1,1,1,1}, {1,1,1,1}};
    for (int i = 0; i < rows; i++) {
        grid[i] = (int *)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            grid[i][j] = grid4_data[i][j];
        }
    }
    assert(func0(grid, rows, cols, capacity) == 4);
    for (int i = 0; i < rows; i++) free(grid[i]);
    free(grid);

    // Test case 5
    rows = 2; cols = 4; capacity = 9;
    grid = (int **)malloc(rows * sizeof(int *));
    int grid5_data[2][4] = {{1,1,1,1}, {1,1,1,1}};
    for (int i = 0; i < rows; i++) {
        grid[i] = (int *)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            grid[i][j] = grid5_data[i][j];
        }
    }
    assert(func0(grid, rows, cols, capacity) == 2);
for (int i = 0; i < rows; i++) free(grid[i]);
    free(grid);

    printf("All tests passed!\n");
    return 0;
}

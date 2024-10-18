#include <stdio.h>
#include <assert.h>
int *func0(int **grid, int N, int k, int *returnSize);

int issame(int *a, int *b, int size) {
    for (int i = 0; i < size; i++) {
        if (a[i] != b[i]) return 0;
    }
    return 1;
}

int main() {
    int size;

    // Test case 1
    int grid1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int *grid1_ptrs[] = {grid1[0], grid1[1], grid1[2]};
    int result1[] = {1, 2, 1};
    int *out1 = func0(grid1_ptrs, 3, 3, &size);
    assert(issame(out1, result1, size));
    free(out1);

    // Test case 2
    int grid2[3][3] = {{5, 9, 3}, {4, 1, 6}, {7, 8, 2}};
    int *grid2_ptrs[] = {grid2[0], grid2[1], grid2[2]};
    int result2[] = {1};
    int *out2 = func0(grid2_ptrs, 3, 1, &size);
    assert(issame(out2, result2, size));
    free(out2);

    // Test case 3
    int grid3[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    int *grid3_ptrs[] = {grid3[0], grid3[1], grid3[2], grid3[3]};
    int result3[] = {1, 2, 1, 2};
    int *out3 = func0(grid3_ptrs, 4, 4, &size);
    assert(issame(out3, result3, size));
    free(out3);

    // Test case 4
    int grid4[4][4] = {{6, 4, 13, 10}, {5, 7, 12, 1}, {3, 16, 11, 15}, {8, 14, 9, 2}};
    int *grid4_ptrs[] = {grid4[0], grid4[1], grid4[2], grid4[3]};
    int result4[] = {1, 10, 1, 10, 1, 10, 1};
    int *out4 = func0(grid4_ptrs, 4, 7, &size);
    assert(issame(out4, result4, size));
    free(out4);
    
    // Test case 5
    int grid5[4][4] = {{8, 14, 9, 2}, {6, 4, 13, 15}, {5, 7, 1, 12}, {3, 10, 11, 16}};
    int *grid5_ptrs[] = {grid5[0], grid5[1], grid5[2], grid5[3]};
    int result5[] = {1, 7, 1, 7, 1};
    int *out5 = func0(grid5_ptrs, 4, 5, &size);
    assert(issame(out5, result5, size));
    free(out5);

    return 0;
}

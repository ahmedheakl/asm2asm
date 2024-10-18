#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
int **func0(int **lst, int lst_size, int *row_sizes, int x, int *return_size);

int issame(int **a, int aSize, int **b, int bSize) {
    if (aSize != bSize) return 0;

    for (int i = 0; i < aSize; i++) {
        if (a[i][0] != b[i][0] || a[i][1] != b[i][1]) return 0;
    }
    return 1;
}

void free_result(int **result, int size) {
    for (int i = 0; i < size; ++i) {
        free(result[i]);
    }
    free(result);
}

int main() {
    int rows, returnSize;
    int **result;

    // Test case 1
    rows = 3;
    int cols1[] = {6, 6, 6};
    int *lst1[] = {(int[]){1,2,3,4,5,6}, (int[]){1,2,3,4,1,6}, (int[]){1,2,3,4,5,1}};
    int *expected1[] = {(int[]){0, 0}, (int[]){1, 4}, (int[]){1, 0}, (int[]){2, 5}, (int[]){2, 0}};
    result = func0(lst1, rows, cols1, 1, &returnSize);
    assert(issame(result, returnSize, expected1, 5));
    free_result(result, returnSize);

    return 0;
}

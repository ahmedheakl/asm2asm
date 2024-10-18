#include <stdio.h>
#include <stdlib.h>

int **func0(int **lst, int lst_size, int *row_sizes, int x, int *return_size) {
    int **out = (int **)malloc(100 * sizeof(int *));
    int count = 0;
    for (int i = 0; i < lst_size; i++) {
        for (int j = row_sizes[i] - 1; j >= 0; j--) {
            if (lst[i][j] == x) {
                out[count] = (int *)malloc(2 * sizeof(int));
                out[count][0] = i;
                out[count][1] = j;
                count++;
            }
        }
    }
    *return_size = count;
    return out;
}

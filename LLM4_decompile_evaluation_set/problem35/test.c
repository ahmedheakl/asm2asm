#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
int *func0(int *l, int size, int *out_size);

int main() {
    int test_array[] = {5, 3, 5, 2, 3, 3, 9, 0, 123};
    int expected_array[] = {0, 2, 3, 5, 9, 123};
    int unique_size;
    int *unique_array = func0(test_array, sizeof(test_array) / sizeof(test_array[0]), &unique_size);

    assert(unique_size == sizeof(expected_array) / sizeof(expected_array[0]));
    for (int i = 0; i < unique_size; i++) {
        assert(unique_array[i] == expected_array[i]);
    }

    free(unique_array);
    printf("All tests passed!\n");

    return 0;
}

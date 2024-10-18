#include <assert.h>
#include <string.h>
int *func0(const int numbers[], int size, int delimiter, int *out_size);

int issame(const int a[], const int b[], int size_a, int size_b) {
    if (size_a != size_b) return 0;
    for (int i = 0; i < size_a; i++) {
        if (a[i] != b[i]) return 0;
    }
    return 1;
}

int main() {
    int out_size;

    // Test with an empty array
    int *result_empty = func0((const int[]){}, 0, 7, &out_size);
    assert(issame(result_empty, (const int[]){}, out_size, 0));
    free(result_empty);

    // Test with an array with elements
    int result_expected1[] = {5, 8, 6, 8, 3, 8, 2};
    int *result1 = func0((const int[]){5, 6, 3, 2}, 4, 8, &out_size);
    assert(issame(result1, result_expected1, out_size, 7));
    free(result1);

    // Test with an array with delimiters equal to elements
    int result_expected2[] = {2, 2, 2, 2, 2};
    int *result2 = func0((const int[]){2, 2, 2}, 3, 2, &out_size);
    assert(issame(result2, result_expected2, out_size, 5));
    free(result2);
    
    return 0;
}

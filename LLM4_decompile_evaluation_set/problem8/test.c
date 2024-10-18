#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char **func0(char **strings, int size, const char *substring, int *out_size);


int issame(char **a, char **b, int size_a, int size_b) {
    if (size_a != size_b) return 0;
    for (int i = 0; i < size_a; i++) {
        if (strcmp(a[i], b[i]) != 0) return 0;
    }
    return 1;
}

int main() {
    int out_size;
    char **result;

    // First test case with empty array and substring "john"
    result = func0(NULL, 0, "john", &out_size);
    assert(out_size == 0 && result == NULL);

    // Second test case
    char *strings1[] = {"xxx", "asd", "xxy", "john doe", "xxxAAA", "xxx"};
    char *expected1[] = {"xxx", "xxxAAA", "xxx"};
    result = func0(strings1, 6, "xxx", &out_size);
    assert(issame(result, expected1, out_size, 3));
    free(result);

    // Third test case
    char *strings2[] = {"xxx", "asd", "aaaxxy", "john doe", "xxxAAA", "xxx"};
    char *expected2[] = {"xxx", "aaaxxy", "xxxAAA", "xxx"};
    result = func0(strings2, 6, "xx", &out_size);
    assert(issame(result, expected2, out_size, 4));
    free(result);

    // Fourth test case
    char *strings3[] = {"grunt", "trumpet", "prune", "gruesome"};
    char *expected3[] = {"grunt", "prune"};
    result = func0(strings3, 4, "run", &out_size);
    assert(issame(result, expected3, out_size, 2));
    free(result);
    
    return 0;
}

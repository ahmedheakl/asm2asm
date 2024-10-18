#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
int *func0(int arr[], int length, int output[2]);

int issame(const int *a, const int *b, int a_length, int b_length) {
    if (a_length != b_length) return 0;
    for (int i = 0; i < a_length; ++i) {
        if (a[i] != b[i]) return 0;
    }
    return 1;
}

int main() {
    int output[2];
    int *result;
    
    int test1[] = {4, 2, 3};
    int expect1[] = {2, 1};
    result = func0(test1, 3, output);
    assert(issame(result, expect1, 2, 2));

    int test2[] = {1, 2, 3};
    int expect2[] = {2, 1};
    result = func0(test2, 3, output);
    assert(issame(result, expect2, 2, 2));

    int test3[] = {};
    result = func0(test3, 0, output);
    assert(result == NULL);

    int test4[] = {5, 0, 3, 0, 4, 2};
    int expect4[] = {0, 1};
    result = func0(test4, 6, output);
    assert(issame(result, expect4, 2, 2));

    int test5[] = {1, 2, 3, 0, 5, 3};
    int expect5[] = {0, 3};
    result = func0(test5, 6, output);
    assert(issame(result, expect5, 2, 2));

    int test6[] = {5, 4, 8, 4, 8};
    int expect6[] = {4, 1};
    result = func0(test6, 5, output);
    assert(issame(result, expect6, 2, 2));

    int test7[] = {7, 6, 7, 1};
    int expect7[] = {6, 1};
    result = func0(test7, 4, output);
    assert(issame(result, expect7, 2, 2));

    int test8[] = {7, 9, 7, 1};
    result = func0(test8, 4, output);
    assert(result == NULL);

    return 0;
}

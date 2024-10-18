#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char** func0(char **lst, int lst_size, int *return_size);

int issame(char **a, char **b, int a_size, int b_size) {
    if (a_size != b_size) return 0;
    for (int i = 0; i < a_size; i++) {
        if (strcmp(a[i], b[i]) != 0) return 0;
    }
    return 1;
}

int main() {
    int size;
    char **result;

    char *test1[] = {"aa", "a", "aaa"};
    char *expected1[] = {"aa"};
    result = func0(test1, 3, &size);
    assert(issame(result, expected1, size, 1));
    free(result);

    char *test2[] = {"school", "AI", "asdf", "b"};
    char *expected2[] = {"AI", "asdf", "school"};
    result = func0(test2, 4, &size);
    assert(issame(result, expected2, size, 3));
    free(result);

    char *test3[] = {"d", "b", "c", "a"};
    result = func0(test3, 4, &size);
    assert(size == 0);
    free(result);

    char *test4[] = {"d", "dcba", "abcd", "a"};
    char *expected4[] = {"abcd", "dcba"};
    result = func0(test4, 4, &size);
    assert(issame(result, expected4, size, 2));
    free(result);

    char *test5[] = {"AI", "ai", "au"};
    char *expected5[] = {"AI", "ai", "au"};
    result = func0(test5, 3, &size);
    assert(issame(result, expected5, size, 3));
    free(result);

    char *test6[] = {"a", "b", "b", "c", "c", "a"};
    result = func0(test6, 6, &size);
    assert(size == 0);
    free(result);

    char *test7[] = {"aaaa", "bbbb", "dd", "cc"};
    char *expected7[] = {"cc", "dd", "aaaa", "bbbb"};
    result = func0(test7, 4, &size);
    assert(issame(result, expected7, size, 4));
    free(result);

    printf("All tests passed!\n");

    return 0;
}

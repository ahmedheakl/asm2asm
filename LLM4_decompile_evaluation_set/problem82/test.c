#include <assert.h>
#include <stdbool.h>
#include <string.h>
char** func0(float* grades, int size);

bool issame(char** a, char** b, int size) {
    for (int i = 0; i < size; i++) {
        if (strcmp(a[i], b[i]) != 0) return false;
    }
    return true;
}

int main() {
    float grades1[] = {4.0, 3, 1.7, 2, 3.5};
    char* expected1[] = {"A+", "B", "C-", "C", "A-"};
    char** result1 = func0(grades1, 5);
    assert(issame(result1, expected1, 5));
    free(result1);

    float grades2[] = {1.2};
    char* expected2[] = {"D+"};
    char** result2 = func0(grades2, 1);
    assert(issame(result2, expected2, 1));
    free(result2);

    float grades3[] = {0.5};
    char* expected3[] = {"D-"};
    char** result3 = func0(grades3, 1);
    assert(issame(result3, expected3, 1));
    free(result3);

    float grades4[] = {0.0};
    char* expected4[] = {"E"};
    char** result4 = func0(grades4, 1);
    assert(issame(result4, expected4, 1));
    free(result4);

    float grades5[] = {1, 0.3, 1.5, 2.8, 3.3};
    char* expected5[] = {"D", "D-", "C-", "B", "B+"};
    char** result5 = func0(grades5, 5);
    assert(issame(result5, expected5, 5));
    free(result5);

    float grades6[] = {0, 0.7};
    char* expected6[] = {"E", "D-"};
    char** result6 = func0(grades6, 2);
    assert(issame(result6, expected6, 2));
    free(result6);

    return 0;
}

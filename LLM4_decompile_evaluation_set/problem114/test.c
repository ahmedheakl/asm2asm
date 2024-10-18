#include <assert.h>
#include <string.h>
#include <stdlib.h>
char **func0(char *lst[], int size);

int issame(char **a, char **b, int size) {
    for (int i = 0; i < size; i++) {
        if (strcmp(a[i], b[i]) != 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char *input1[] = {"1234567"};
    char *expected1[] = {"the number of odd elements 4 in the string 4 of the 4 input."};
    char **result1 = func0(input1, 1);
    assert(issame(result1, expected1, 1));

    char *input2[] = {"3", "11111111"};
    char *expected2[] = {
        "the number of odd elements 1 in the string 1 of the 1 input.",
        "the number of odd elements 8 in the string 8 of the 8 input."
    };
    char **result2 = func0(input2, 2);
    assert(issame(result2, expected2, 2));

    char *input3[] = {"271", "137", "314"};
    char *expected3[] = {
        "the number of odd elements 2 in the string 2 of the 2 input.",
        "the number of odd elements 3 in the string 3 of the 3 input.",
        "the number of odd elements 2 in the string 2 of the 2 input."
    };
    char **result3 = func0(input3, 3);
    assert(issame(result3, expected3, 3));

    // Free the allocated memory
    for (int i = 0; i < 1; i++) free(result1[i]);
    free(result1);
    for (int i = 0; i < 2; i++) free(result2[i]);
    free(result2);
    for (int i = 0; i < 3; i++) free(result3[i]);
    free(result3);

    return 0;
}

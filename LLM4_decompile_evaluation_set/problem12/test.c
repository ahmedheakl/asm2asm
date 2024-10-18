#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
char *func0(const char *a, const char *b);

int main() {
    char *result;

    result = func0("111000", "101010");
    assert(strcmp(result, "010010") == 0);
    free(result);

    result = func0("1", "1");
    assert(strcmp(result, "0") == 0);
    free(result);

    result = func0("0101", "0000");
    assert(strcmp(result, "0101") == 0);
    free(result);

    return 0;
}

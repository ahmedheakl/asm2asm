#include <assert.h>
#include <string.h>
char *func0(int n);

int main() {
    char *result;

    result = func0(0);
    assert(strcmp(result, "0") == 0);
    free(result);

    result = func0(3);
    assert(strcmp(result, "0 1 2 3") == 0);
    free(result);

    result = func0(10);
    assert(strcmp(result, "0 1 2 3 4 5 6 7 8 9 10") == 0);
    free(result);

    return 0;
}

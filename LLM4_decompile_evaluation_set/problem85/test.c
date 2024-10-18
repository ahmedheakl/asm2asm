#include <assert.h>
#include <string.h>
char* func0(int N);

int main() {
    char* result;

    result = func0(1000);
    assert(strcmp(result, "1") == 0);
    free(result);

    result = func0(150);
    assert(strcmp(result, "110") == 0);
    free(result);

    result = func0(147);
    assert(strcmp(result, "1100") == 0);
    free(result);

    result = func0(333);
    assert(strcmp(result, "1001") == 0);
    free(result);

    result = func0(963);
    assert(strcmp(result, "10010") == 0);
    free(result);

    return 0;
}

#include <assert.h>
#include <string.h>
char* func0(int x, int shift);

int main() {
    assert(strcmp(func0(100, 2), "001") == 0);
    assert(strcmp(func0(12, 2), "12") == 0);
    assert(strcmp(func0(97, 8), "79") == 0);
    assert(strcmp(func0(12, 1), "21") == 0);
    assert(strcmp(func0(11, 101), "11") == 0);

    return 0;
}

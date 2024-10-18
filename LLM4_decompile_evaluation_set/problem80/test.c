#include <assert.h>
#include <string.h>
char* func0(int decimal);

int main() {
    char* binary;

    binary = func0(0);
    assert(strcmp(binary, "db0db") == 0);
    free(binary);

    binary = func0(32);
    assert(strcmp(binary, "db100000db") == 0);
    free(binary);

    binary = func0(103);
    assert(strcmp(binary, "db1100111db") == 0);
    free(binary);

    binary = func0(15);
    assert(strcmp(binary, "db1111db") == 0);
    free(binary);

    return 0;
}

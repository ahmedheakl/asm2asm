#include <stdio.h>
#include <assert.h>
#include <string.h>
const char* func0(int interval1_start, int interval1_end, int interval2_start, int interval2_end);

int main() {
    assert(strcmp(func0(1, 2, 2, 3), "NO") == 0);
    assert(strcmp(func0(-1, 1, 0, 4), "NO") == 0);
    assert(strcmp(func0(-3, -1, -5, 5), "YES") == 0);
    assert(strcmp(func0(-2, 2, -4, 0), "YES") == 0);
    assert(strcmp(func0(-11, 2, -1, -1), "NO") == 0);
    assert(strcmp(func0(1, 2, 3, 5), "NO") == 0);
    assert(strcmp(func0(1, 2, 1, 2), "NO") == 0);
    assert(strcmp(func0(-2, -2, -3, -2), "NO") == 0);
    
    return 0;
}

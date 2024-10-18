#include <stdio.h>
#include <assert.h>
int func0(int n, int p);

int main() {
    assert(func0(3, 5) == 3);
    assert(func0(1101, 101) == 2);
    assert(func0(0, 101) == 1);
    assert(func0(3, 11) == 8);
    assert(func0(100, 101) == 1);
    assert(func0(30, 5) == 4);
    assert(func0(31, 5) == 3);

    printf("All tests passed.\n");
    return 0;
}

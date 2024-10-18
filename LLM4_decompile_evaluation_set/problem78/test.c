#include <assert.h>
int func0(int a);

int main() {
    assert(func0(1) == 1);
    assert(func0(2) == 0);
    assert(func0(-1) == 1);
    assert(func0(64) == 1);
    assert(func0(180) == 0);
    assert(func0(1000) == 1);
    assert(func0(0) == 1);
    assert(func0(1729) == 0);

    printf("All tests passed.\n");
    return 0;
}

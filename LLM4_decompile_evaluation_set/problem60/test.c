#include <assert.h>
int func0(int n);

int main() {
    assert(func0(15) == 5);
    assert(func0(27) == 3);
    assert(func0(63) == 7);
    assert(func0(330) == 11);
    assert(func0(13195) == 29);

    return 0;
}

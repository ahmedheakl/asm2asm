#include <assert.h>
int func0(int a, int b);

int main() {
    assert(func0(3, 7) == 1);
    assert(func0(10, 15) == 5);
    assert(func0(49, 14) == 7);
    assert(func0(144, 60) == 12);

    return 0;
}

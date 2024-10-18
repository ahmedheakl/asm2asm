#include <assert.h>
int func0(int n);

int main() {
    assert(func0(1) == 1);
    assert(func0(2) == 18);
    assert(func0(3) == 180);
    assert(func0(4) == 1800);
    assert(func0(5) == 18000);

    return 0;
}

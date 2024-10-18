#include <assert.h>
int func0(int n);

int main() {
    assert(func0(5) == 1);
    assert(func0(6) == 4);
    assert(func0(10) == 36);
    assert(func0(100) == 53361);

    return 0;
}

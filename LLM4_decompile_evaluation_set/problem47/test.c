#include <stdio.h>
#include <assert.h>
int func0(int n);

int main() {
    assert(func0(5) == 4);
    assert(func0(8) == 28);
    assert(func0(10) == 104);
    assert(func0(12) == 386);

    return 0;
}

#include <assert.h>
int func0(int n);

int main() {
    assert(func0(1) == 1);
    assert(func0(6) == 21);
    assert(func0(11) == 66);
    assert(func0(30) == 465);
    assert(func0(100) == 5050);

    return 0;
}

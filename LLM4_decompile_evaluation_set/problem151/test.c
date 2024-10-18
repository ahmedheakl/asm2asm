#include <assert.h>
int func0(int n, int x, int y);

int main() {
    assert(func0(7, 34, 12) == 34);
    assert(func0(15, 8, 5) == 5);
    assert(func0(3, 33, 5212) == 33);
    assert(func0(1259, 3, 52) == 3);
    assert(func0(7919, -1, 12) == -1);
    assert(func0(3609, 1245, 583) == 583);
    assert(func0(91, 56, 129) == 129);
    assert(func0(6, 34, 1234) == 1234);
    assert(func0(1, 2, 0) == 0);
    assert(func0(2, 2, 0) == 2);

    return 0;
}

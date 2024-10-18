#include <assert.h>
#include <stdlib.h>
int func0(int x, int y);

int main() {
    assert(func0(0, 1) == 1);
    assert(func0(1, 0) == 1);
    assert(func0(2, 3) == 5);
    assert(func0(5, 7) == 12);
    assert(func0(7, 5) == 12);
    for (int i = 0; i < 100; i += 1) {
        int x = rand() % 1000;
        int y = rand() % 1000;
        assert(func0(x, y) == x + y);
    }
    return 0;
}

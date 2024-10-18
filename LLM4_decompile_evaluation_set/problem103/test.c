#include <assert.h>
int func0(int x, int y);

int main() {
    assert(func0(12, 15) == 14);
    assert(func0(13, 12) == -1);
    assert(func0(33, 12354) == 12354);
    assert(func0(5234, 5233) == -1);
    assert(func0(6, 29) == 28);
    assert(func0(27, 10) == -1);
    assert(func0(7, 7) == -1);
    assert(func0(546, 546) == 546);

    return 0;
}

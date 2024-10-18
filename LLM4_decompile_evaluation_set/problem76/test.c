#include <assert.h>
int func0(int a);

int main() {
    assert(func0(5) == 0);
    assert(func0(30) == 1);
    assert(func0(8) == 1); // 8 = 2 * 2 * 2
    assert(func0(10) == 0);
    assert(func0(125) == 1); // 125 = 5 * 5 * 5 (three times the same prime)
    assert(func0(3 * 5 * 7) == 1);
    assert(func0(3 * 6 * 7) == 0);
    assert(func0(9 * 9 * 9) == 0);
    assert(func0(11 * 9 * 9) == 0);
    assert(func0(11 * 13 * 7) == 1);

    printf("All tests passed!\n");

    return 0;
}

#include <assert.h>
int func0(const char *s, int n);

int main() {
    assert(func0("5 apples and 6 oranges", 19) == 8);
    assert(func0("5 apples and 6 oranges", 21) == 10);
    assert(func0("0 apples and 1 oranges", 3) == 2);
    assert(func0("1 apples and 0 oranges", 3) == 2);
    assert(func0("2 apples and 3 oranges", 100) == 95);
    assert(func0("2 apples and 3 oranges", 5) == 0);
    assert(func0("1 apples and 100 oranges", 120) == 19);

    return 0;
}

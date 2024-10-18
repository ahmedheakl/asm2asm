#include <assert.h>
int func0(const char *s);

int main() {
    assert(func0("abcde") == 2);
    assert(func0("Alone") == 3);
    assert(func0("key") == 2);
    assert(func0("bye") == 1);
    assert(func0("keY") == 2);
    assert(func0("bYe") == 1);
    assert(func0("ACEDY") == 3);

    return 0;
}

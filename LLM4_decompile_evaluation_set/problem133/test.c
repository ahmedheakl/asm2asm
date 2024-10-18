#include <assert.h>

int func0(const char *str);

int main() {
    assert(func0("[[]]") == 1);
    assert(func0("[]]]]]]][[[[[]") == 0);
    assert(func0("[][]") == 0);
    assert(func0("[]") == 0);
    assert(func0("[[[[]]]]") == 1);
    assert(func0("[]]]]]]]]]]") == 0);
    assert(func0("[][][[]]") == 1);
    assert(func0("[[]") == 0);
    assert(func0("[]]") == 0);
    assert(func0("[[]][[") == 1);
    assert(func0("[[][]]") == 1);
    assert(func0("") == 0);
    assert(func0("[[[[[[[[") == 0);
    assert(func0("]]]]]]]]") == 0);

    return 0;
}

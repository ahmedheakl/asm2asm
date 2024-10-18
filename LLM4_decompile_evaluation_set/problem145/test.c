#include <assert.h>
int func0(const char* x, const char* n);

int main() {
    assert(func0("1/5", "5/1") == 1);
    assert(func0("1/6", "2/1") == 0);
    assert(func0("5/1", "3/1") == 1);
    assert(func0("7/10", "10/2") == 0);
    assert(func0("2/10", "50/10") == 1);
    assert(func0("7/2", "4/2") == 1);
    assert(func0("11/6", "6/1") == 1);
    assert(func0("2/3", "5/2") == 0);
    assert(func0("5/2", "3/5") == 0);
    assert(func0("2/4", "8/4") == 1);
    assert(func0("2/4", "4/2") == 1);
    assert(func0("1/5", "5/1") == 1);
    assert(func0("1/5", "1/5") == 0);

    return 0;
}

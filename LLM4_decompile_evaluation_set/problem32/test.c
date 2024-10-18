#include <assert.h>
#include <stdbool.h>
bool func0(long long n);

int main() {
    assert(func0(6) == false);
    assert(func0(101) == true);
    assert(func0(11) == true);
    assert(func0(13441) == true);
    assert(func0(61) == true);
    assert(func0(4) == false);
    assert(func0(1) == false);
    assert(func0(5) == true);
    assert(func0(11) == true);
    assert(func0(17) == true);
    assert(func0(5 * 17) == false);
    assert(func0(11 * 7) == false);
    assert(func0(13441 * 19) == false);

    return 0;
}

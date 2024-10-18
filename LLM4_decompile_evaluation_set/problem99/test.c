#include <assert.h>
int func0(const char *s);

int main() {
    assert(func0("aBCdEf") == 1);
    assert(func0("abcdefg") == 0);
    assert(func0("dBBE") == 0);
    assert(func0("B") == 0);
    assert(func0("U") == 1);
    assert(func0("") == 0);
    assert(func0("EEEE") == 2);

    return 0;
}

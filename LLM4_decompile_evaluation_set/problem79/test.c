#include <assert.h>
int func0(const char* num);

int main() {
    assert(func0("AB") == 1);
    assert(func0("1077E") == 2);
    assert(func0("ABED1A33") == 4);
    assert(func0("2020") == 2);
    assert(func0("123456789ABCDEF0") == 6);
    assert(func0("112233445566778899AABBCCDDEEFF00") == 12);
    assert(func0("") == 0);

    return 0;
}

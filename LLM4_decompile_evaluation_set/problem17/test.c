#include <assert.h>
int func0(const char *str);

int main() {
    assert(func0("") == 0);
    assert(func0("abcde") == 5);
    assert(func0("abcdecadeCADE") == 5);
    assert(func0("aaaaAAAAaaaa") == 1);
    assert(func0("Jerry jERRY JeRRRY") == 4);

    return 0;
}

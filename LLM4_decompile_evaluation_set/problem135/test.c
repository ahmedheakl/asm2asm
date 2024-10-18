#include <assert.h>
int func0(const char *txt);

int main() {
    assert(func0("apple") == 0);
    assert(func0("apple pi e") == 1);
    assert(func0("eeeee") == 0);
    assert(func0("A") == 1);
    assert(func0("Pumpkin pie ") == 0);
    assert(func0("Pumpkin pie 1") == 0);
    assert(func0("") == 0);
    assert(func0("eeeee e ") == 0);
    assert(func0("apple pie") == 0);
    assert(func0("apple pi e ") == 0);

    return 0;
}
#include <assert.h>
#include <stdbool.h>
bool func0(const char *a, const char *b);

int main() {
    assert(func0("xyzw", "xyw") == false);
    assert(func0("yello", "ell") == true);
    assert(func0("whattup", "ptut") == false);
    assert(func0("efef", "fee") == true);
    assert(func0("abab", "aabb") == false);
    assert(func0("winemtt", "tinem") == true);

    return 0;
}

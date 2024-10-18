#include <assert.h>
#include <stdbool.h>
bool func0(const char *s0, const char *s1);

int main() {
    assert(func0("eabcdzzzz", "dddzzzzzzzddeddabc") == true);
    assert(func0("abcd", "dddddddabc") == true);
    assert(func0("dddddddabc", "abcd") == true);
    assert(func0("eabcd", "dddddddabc") == false);
    assert(func0("abcd", "dddddddabce") == false);
    assert(func0("eabcdzzzz", "dddzzzzzzzddddabc") == false);
    assert(func0("aabb", "aaccc") == false);

    return 0;
}

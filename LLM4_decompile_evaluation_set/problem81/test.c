#include <assert.h>
#include <stdbool.h>
bool func0(const char* s);

int main() {
    assert(func0("a") == false);
    assert(func0("aa") == false);
    assert(func0("abcd") == true);
    assert(func0("aabb") == false);
    assert(func0("adb") == true);
    assert(func0("xyy") == false);
    assert(func0("iopaxpoi") == true);
    assert(func0("iopaxioi") == false);

    return 0;
}

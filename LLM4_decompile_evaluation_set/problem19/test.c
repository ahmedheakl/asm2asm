#include <assert.h>
int func0(const char *str, const char *substring);

int main() {
    assert(func0("", "x") == 0);
    assert(func0("xyxyxyx", "x") == 4);
    assert(func0("cacacacac", "cac") == 4);
    assert(func0("john doe", "john") == 1);

    return 0;
}

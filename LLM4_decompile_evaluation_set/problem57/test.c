#include <assert.h>
#include <stdbool.h>
bool func0(const char *brackets);

int main() {
    assert(func0("<>"));
    assert(func0("<<><>>"));
    assert(func0("<><><<><>><>"));
    assert(func0("<><><<<><><>><>><<><><<>>>"));
    assert(!func0("<<<><>>>>"));
    assert(!func0("><<>"));
    assert(!func0("<"));
    assert(!func0("<<<<"));
    assert(!func0(">"));
    assert(!func0("<<>"));
    assert(!func0("<><><<><>><>><<>"));
    assert(!func0("<><><<><>><>>><>"));

    return 0;
}

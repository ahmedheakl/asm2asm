#include <stdio.h>
#include <string.h>
#include <assert.h>
void func0(const char *s, char *out);

int main() {
    char encrypted[100]; // Buffer should be large enough to hold the encrypted string

    func0("hi", encrypted);
    assert(strcmp(encrypted, "lm") == 0);

    func0("asdfghjkl", encrypted);
    assert(strcmp(encrypted, "ewhjklnop") == 0);

    func0("gf", encrypted);
    assert(strcmp(encrypted, "kj") == 0);

    func0("et", encrypted);
    assert(strcmp(encrypted, "ix") == 0);

    func0("faewfawefaewg", encrypted);
    assert(strcmp(encrypted, "jeiajeaijeiak") == 0);

    func0("hellomyfriend", encrypted);
    assert(strcmp(encrypted, "lippsqcjvmirh") == 0);

    func0("dxzdlmnilfuhmilufhlihufnmlimnufhlimnufhfucufh", encrypted);
    assert(strcmp(encrypted, "hbdhpqrmpjylqmpyjlpmlyjrqpmqryjlpmqryjljygyjl") == 0);

    func0("a", encrypted);
    assert(strcmp(encrypted, "e") == 0);

    return 0;
}

#include <stdio.h>
#include <assert.h>
#include <string.h>
char *func0(const char *word);

int main() {
    assert(strcmp(func0("yogurt"), "u") == 0);
    assert(strcmp(func0("full"), "u") == 0);
    assert(strcmp(func0("easy"), "") == 0);
    assert(strcmp(func0("eAsy"), "") == 0);
    assert(strcmp(func0("ali"), "") == 0);
    assert(strcmp(func0("bad"), "a") == 0);
    assert(strcmp(func0("most"), "o") == 0);
    assert(strcmp(func0("ab"), "") == 0);
    assert(strcmp(func0("ba"), "") == 0);
    assert(strcmp(func0("quick"), "") == 0);
    assert(strcmp(func0("anime"), "i") == 0);
    assert(strcmp(func0("Asia"), "") == 0);
    assert(strcmp(func0("Above"), "o") == 0);

    return 0;
}

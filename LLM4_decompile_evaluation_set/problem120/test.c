#include <stdio.h>
#include <assert.h>
const char *func0(const char *s1, const char *s2);

int main() {
    assert(strcmp(func0("()(", ")"), "Yes") == 0);
    assert(strcmp(func0(")", ")"), "No") == 0);
    assert(strcmp(func0("(()(())", "())())"), "No") == 0);
    assert(strcmp(func0(")())", "(()()("), "Yes") == 0);
    assert(strcmp(func0("(())))", "(()())(("), "Yes") == 0);
    assert(strcmp(func0("()", "())"), "No") == 0);
    assert(strcmp(func0("(()(", "()))()"), "Yes") == 0);
    assert(strcmp(func0("((((", "((())"), "No") == 0);
    assert(strcmp(func0(")(()", "(()("), "No") == 0);
    assert(strcmp(func0(")(", ")("), "No") == 0);
    assert(strcmp(func0("(", ")"), "Yes") == 0);
    assert(strcmp(func0(")", "("), "Yes") == 0);

    return 0;
}

#include <assert.h>
#include <stdbool.h>
bool func0(const char* str);

int main() {
    assert(func0("Hello") == true);
    assert(func0("abcdcba") == true);
    assert(func0("kittens") == true);
    assert(func0("orange") == false);
    assert(func0("wow") == true);
    assert(func0("world") == true);
    assert(func0("MadaM") == true);
    assert(func0("Wow") == true);
    assert(func0("") == false);
    assert(func0("HI") == true);
    assert(func0("go") == true);
    assert(func0("gogo") == false);
    assert(func0("aaaaaaaaaaaaaaa") == false);
    assert(func0("Madam") == true);
    assert(func0("M") == false);
    assert(func0("0") == false);
    
    return 0;
}

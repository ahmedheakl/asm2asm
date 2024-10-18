#include <assert.h>
#include <string.h>
char* func0(int n, int m);

int main() {
    assert(strcmp(func0(1, 5), "11") == 0);
    assert(strcmp(func0(7, 13), "1010") == 0);
    assert(strcmp(func0(964, 977), "1111001010") == 0);
    assert(strcmp(func0(996, 997), "1111100100") == 0);
    assert(strcmp(func0(560, 851), "1011000001") == 0);
    assert(strcmp(func0(185, 546), "101101101") == 0);
    assert(strcmp(func0(362, 496), "110101101") == 0);
    assert(strcmp(func0(350, 902), "1001110010") == 0);
    assert(strcmp(func0(197, 233), "11010111") == 0);
    assert(strcmp(func0(7, 5), "-1") == 0);
    assert(strcmp(func0(5, 1), "-1") == 0);
    assert(strcmp(func0(5, 5), "101") == 0);

    return 0;
}

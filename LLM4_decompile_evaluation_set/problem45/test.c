#include <stdio.h>
#include <assert.h>
#include <string.h>
void func0(int x, int base, char *out);

int main() {
    char buffer[33];
    
    func0(8, 3, buffer);
    assert(strcmp(buffer, "22") == 0);
    
    func0(9, 3, buffer);
    assert(strcmp(buffer, "100") == 0);
    
    func0(234, 2, buffer);
    assert(strcmp(buffer, "11101010") == 0);
    
    func0(16, 2, buffer);
    assert(strcmp(buffer, "10000") == 0);
    
    func0(8, 2, buffer);
    assert(strcmp(buffer, "1000") == 0);
    
    func0(7, 2, buffer);
    assert(strcmp(buffer, "111") == 0);
    
    for (int x = 2; x < 8; x++) {
        char expected[33];
        sprintf(expected, "%d", x);
        func0(x, x + 1, buffer);
        assert(strcmp(buffer, expected) == 0);
    }

    return 0;
}

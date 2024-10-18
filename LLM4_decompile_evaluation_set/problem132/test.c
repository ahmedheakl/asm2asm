#include <assert.h>
int func0(int n);

int main(){
    assert(func0(5) == 5);
    assert(func0(54) == 5);
    assert(func0(120) == 1);
    assert(func0(5014) == 5);
    assert(func0(98765) == 315);
    assert(func0(5576543) == 2625);
    assert(func0(2468) == 0);

    return 0;
}

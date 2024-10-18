#include <assert.h>
int func0(const char *S);

int main() {
    assert(func0("Hello world") == 0);
    assert(func0("Is the sky blue?") == 0);
    assert(func0("I love It !") == 1);
    assert(func0("bIt") == 0);
    assert(func0("I feel good today. I will be productive. will kill It") == 2);
    assert(func0("You and I are going for a walk") == 0);

    return 0;
}

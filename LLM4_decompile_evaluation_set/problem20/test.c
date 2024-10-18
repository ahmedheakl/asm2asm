#include <assert.h>
#include <string.h>
const char* func0(const char* numbers);

int main() {
    assert(strcmp(func0(""), "") == 0);
    assert(strcmp(func0("three"), "three") == 0);
    assert(strcmp(func0("three five nine"), "three five nine") == 0);
    assert(strcmp(func0("five zero four seven nine eight"), "zero four five seven eight nine") == 0);
    assert(strcmp(func0("six five four three two one zero"), "zero one two three four five six") == 0);

    return 0;
}

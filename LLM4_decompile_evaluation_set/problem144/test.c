#include <assert.h>
#include <string.h>
void func0(const char* sentence, char* out);

int main() {
    char output[101];

    func0("This is a test", output);
    assert(strcmp(output, "is") == 0);

    func0("lets go for swimming", output);
    assert(strcmp(output, "go for") == 0);

    func0("there is no place available here", output);
    assert(strcmp(output, "there is no place") == 0);

    func0("Hi I am Hussein", output);
    assert(strcmp(output, "Hi am Hussein") == 0);

    func0("go for it", output);
    assert(strcmp(output, "go for it") == 0);

    func0("here", output);
    assert(strcmp(output, "") == 0);

    func0("here is", output);
    assert(strcmp(output, "is") == 0);

    return 0;
}

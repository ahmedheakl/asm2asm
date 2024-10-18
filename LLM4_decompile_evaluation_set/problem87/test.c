#include <assert.h>
#include <string.h>
char* func0(const char* s);

int main() {
    char* result;

    result = func0("Hi");
    assert(strcmp(result, "Hi") == 0);
    free(result);

    result = func0("hello");
    assert(strcmp(result, "ehllo") == 0);
    free(result);

    result = func0("number");
    assert(strcmp(result, "bemnru") == 0);
    free(result);

    result = func0("abcd");
    assert(strcmp(result, "abcd") == 0);
    free(result);

    result = func0("Hello World!!!");
    assert(strcmp(result, "Hello !!!Wdlor") == 0);
    free(result);

    result = func0("");
    assert(strcmp(result, "") == 0);
    free(result);

    result = func0("Hi. My name is Mister Robot. How are you?");
    assert(strcmp(result, ".Hi My aemn is Meirst .Rboot How aer ?ouy") == 0);
    free(result);

    return 0;
}

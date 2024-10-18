#include <assert.h>
#include <string.h>
void func0(const char *s, const char *c, char *result, char *palindrome);

int main() {
    char result[100];
    char palindrome[6];

    func0("abcde", "ae", result, palindrome);
    assert(strcmp(result, "bcd") == 0 && strcmp(palindrome, "False") == 0);

    func0("abcdef", "b", result, palindrome);
    assert(strcmp(result, "acdef") == 0 && strcmp(palindrome, "False") == 0);

    func0("abcdedcba", "ab", result, palindrome);
    assert(strcmp(result, "cdedc") == 0 && strcmp(palindrome, "True") == 0);

    func0("dwik", "w", result, palindrome);
    assert(strcmp(result, "dik") == 0 && strcmp(palindrome, "False") == 0);

    func0("a", "a", result, palindrome);
    assert(strcmp(result, "") == 0 && strcmp(palindrome, "True") == 0);

    func0("abcdedcba", "", result, palindrome);
    assert(strcmp(result, "abcdedcba") == 0 && strcmp(palindrome, "True") == 0);

    func0("abcdedcba", "v", result, palindrome);
    assert(strcmp(result, "abcdedcba") == 0 && strcmp(palindrome, "True") == 0);

    func0("vabba", "v", result, palindrome);
    assert(strcmp(result, "abba") == 0 && strcmp(palindrome, "True") == 0);

    func0("mamma", "mia", result, palindrome);
    assert(strcmp(result, "") == 0 && strcmp(palindrome, "True") == 0);

    return 0;
}

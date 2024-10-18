#include <assert.h>
#include <string.h>
char *func0(char *words[], int count);

int main() {
    char *words1[] = {"name", "of", "string"};
    assert(strcmp(func0(words1, 3), "string") == 0);

    char *words2[] = {"name", "enam", "game"};
    assert(strcmp(func0(words2, 3), "enam") == 0);

    char *words3[] = {"aaaaaaa", "bb", "cc"};
    assert(strcmp(func0(words3, 3), "aaaaaaa") == 0);

    char *words4[] = {"abc", "cba"};
    assert(strcmp(func0(words4, 2), "abc") == 0);

    char *words5[] = {"play", "this", "game", "of", "footbott"};
    assert(strcmp(func0(words5, 5), "footbott") == 0);

    char *words6[] = {"we", "are", "gonna", "rock"};
    assert(strcmp(func0(words6, 4), "gonna") == 0);

    char *words7[] = {"we", "are", "a", "mad", "nation"};
    assert(strcmp(func0(words7, 5), "nation") == 0);

    char *words8[] = {"this", "is", "a", "prrk"};
    assert(strcmp(func0(words8, 4), "this") == 0);

    char *words9[] = {"b"};
    assert(strcmp(func0(words9, 1), "b") == 0);

    char *words10[] = {"play", "play", "play"};
    assert(strcmp(func0(words10, 3), "play") == 0);

    return 0;
}

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
char **func0(const char *s, int n, int *returnSize);

int issame(char **a, int aSize, char **b, int bSize) {
    if (aSize != bSize) return 0;
    for (int i = 0; i < aSize; i++) {
        if (strcmp(a[i], b[i]) != 0) return 0;
    }
    return 1;
}

void free_words(char **words, int count) {
    for (int i = 0; i < count; i++) {
        free(words[i]);
    }
    free(words);
}

int main() {
    int size;
    char **words;
    
    words = func0("Mary had a little lamb", 4, &size);
    char *expected1[] = {"little"};
    assert(issame(words, size, expected1, 1));
    free_words(words, size);

    words = func0("Mary had a little lamb", 3, &size);
    char *expected2[] = {"Mary", "lamb"};
    assert(issame(words, size, expected2, 2));
    free_words(words, size);

    words = func0("simple white space", 2, &size);
    assert(size == 0);
    free_words(words, size);

    words = func0("Hello world", 4, &size);
    char *expected3[] = {"world"};
    assert(issame(words, size, expected3, 1));
    free_words(words, size);

    words = func0("Uncle sam", 3, &size);
    char *expected4[] = {"Uncle"};
    assert(issame(words, size, expected4, 1));
    free_words(words, size);

    words = func0("", 4, &size);
    assert(size == 0);
    free_words(words, size);

    words = func0("a b c d e f", 1, &size);
    char *expected5[] = {"b", "c", "d", "f"};
    assert(issame(words, size, expected5, 4));
    free_words(words, size);

    return 0;
}

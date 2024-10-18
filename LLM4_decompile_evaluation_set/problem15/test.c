#include <assert.h>
#include <string.h>
char **func0(const char *str, int *count);

int issame(char **a, int a_size, char **b, int b_size) {
    if (a_size != b_size) return 0;
    for (int i = 0; i < a_size; i++) {
        if (strcmp(a[i], b[i]) != 0) return 0;
    }
    return 1;
}

void free_prefixes(char **prefixes, int count) {
    for (int i = 0; i < count; i++) {
        free(prefixes[i]);
    }
    free(prefixes);
}

int main() {
    int count;
    char **result;
    
    result = func0("", &count);
    assert(issame(result, 0, NULL, 0));
    free_prefixes(result, count);

    char *expected1[] = {"a", "as", "asd", "asdf", "asdfg", "asdfgh"};
    result = func0("asdfgh", &count);
    assert(issame(result, count, expected1, 6));
    free_prefixes(result, count);

    char *expected2[] = {"W", "WW", "WWW"};
    result = func0("WWW", &count);
    assert(issame(result, count, expected2, 3));
    free_prefixes(result, count);

    return 0;
}

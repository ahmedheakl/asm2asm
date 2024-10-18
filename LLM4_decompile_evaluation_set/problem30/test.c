#include <assert.h>
#include <stdio.h>
int func0(char** strings, int count, const char* prefix, char*** out);

// Helper function to compare two arrays of strings
int issame(char** a, int a_count, char** b, int b_count) {
    if (a_count != b_count) return 0;
    for (int i = 0; i < a_count; i++) {
        if (strcmp(a[i], b[i]) != 0) return 0;
    }
    return 1;
}

int main() {
    char** result;
    int count;

    count = func0((char*[]){}, 0, "john", &result);
    assert(issame(result, count, (char*[]){}, 0));
    free(result);

    char* strings[] = {"xxx", "asd", "xxy", "john doe", "xxxAAA", "xxx"};
    char* expected[] = {"xxx", "xxxAAA", "xxx"};
    count = func0(strings, 6, "xxx", &result);
    assert(issame(result, count, expected, 3));
    free(result);

    return 0;
}

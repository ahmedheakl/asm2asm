#include <assert.h>
#include <stdlib.h>
int *func0(const char *music_string, int *count);

int issame(const int *a, int a_size, const int *b, int b_size) {
    if (a_size != b_size) return 0;
    for (int i = 0; i < a_size; i++) {
        if (a[i] != b[i]) return 0;
    }
    return 1;
}

int main() {
    int count;
    int *result;

    result = func0("", &count);
    assert(issame(result, count, (int[]){}, 0));
    free(result);

    result = func0("o o o o", &count);
    assert(issame(result, count, (int[]){4, 4, 4, 4}, 4));
    free(result);

    result = func0(".| .| .| .|", &count);
    assert(issame(result, count, (int[]){1, 1, 1, 1}, 4));
    free(result);

    result = func0("o| o| .| .| o o o o", &count);
    assert(issame(result, count, (int[]){2, 2, 1, 1, 4, 4, 4, 4}, 8));
    free(result);

    result = func0("o| .| o| .| o o| o o|", &count);
    assert(issame(result, count, (int[]){2, 1, 2, 1, 4, 2, 4, 2}, 8));
    free(result);

    return 0;
}

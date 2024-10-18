#include <assert.h>
void func0(int *numbers, int size, int *result);

int issame(const int *a, const int *b, int size) {
    for (int i = 0; i < size; i++) {
        if (a[i] != b[i]) return 0;
    }
    return 1;
}

int main() {
    int result[2];

    // First test case
    func0((int[]){}, 0, result);
    assert(issame(result, (const int[]){0, 1}, 2));

    // Second test case
    func0((int[]){1, 1, 1}, 3, result);
    assert(issame(result, (const int[]){3, 1}, 2));

    // Third test case
    func0((int[]){100, 0}, 2, result);
    assert(issame(result, (const int[]){100, 0}, 2));

    // Fourth test case
    func0((int[]){3, 5, 7}, 3, result);
    assert(issame(result, (const int[]){3 + 5 + 7, 3 * 5 * 7}, 2));

    // Fifth test case
    func0((int[]){10}, 1, result);
    assert(issame(result, (const int[]){10, 10}, 2));
    
    return 0;
}

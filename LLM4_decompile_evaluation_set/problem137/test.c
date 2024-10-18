#include <assert.h>
void func0(const int *lst, int size, int result[2]);

int issame(const int a[2], const int b[2]) {
    return a[0] == b[0] && a[1] == b[1];
}

int main() {
    int result[2];
    
    func0((int[]){2, 4, 1, 3, 5, 7}, 6, result);
    assert(issame(result, (int[]){0, 1}));

    func0((int[]){2, 4, 1, 3, 5, 7, 0}, 7, result);
    assert(issame(result, (int[]){0, 1}));

    func0((int[]){1, 3, 2, 4, 5, 6, -2}, 7, result);
    assert(issame(result, (int[]){-2, 1}));

    func0((int[]){4, 5, 3, 6, 2, 7, -7}, 7, result);
    assert(issame(result, (int[]){-7, 2}));

    func0((int[]){7, 3, 8, 4, 9, 2, 5, -9}, 8, result);
    assert(issame(result, (int[]){-9, 2}));

    func0((int[]){}, 0, result);
    assert(issame(result, (int[]){0, 0}));

    func0((int[]){0}, 1, result);
    assert(issame(result, (int[]){0, 0}));

    func0((int[]){-1, -3, -5, -6}, 4, result);
    assert(issame(result, (int[]){-1, 0}));

    func0((int[]){-1, -3, -5, -6, 0}, 5, result);
    assert(issame(result, (int[]){-1, 0}));

    func0((int[]){-6, -4, -4, -3, 1}, 5, result);
    assert(issame(result, (int[]){-3, 1}));

    func0((int[]){-6, -4, -4, -3, -100, 1}, 6, result);
    assert(issame(result, (int[]){-3, 1}));

    return 0;
}

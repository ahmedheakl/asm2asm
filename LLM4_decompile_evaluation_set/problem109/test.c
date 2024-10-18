#include <assert.h>
int func0(int *n, int size);

int main() {
    assert(func0((int[]){}, 0) == 0);
    assert(func0((int[]){-1, -2, 0}, 3) == 0);
    assert(func0((int[]){1, 1, 2, -2, 3, 4, 5}, 7) == 6);
    assert(func0((int[]){1, 6, 9, -6, 0, 1, 5}, 7) == 5);
    assert(func0((int[]){1, 100, 98, -7, 1, -1}, 6) == 4);
    assert(func0((int[]){12, 23, 34, -45, -56, 0}, 6) == 5);
    assert(func0((int[]){-0, 1}, 2) == 1);
    assert(func0((int[]){1}, 1) == 1);

    return 0;
}

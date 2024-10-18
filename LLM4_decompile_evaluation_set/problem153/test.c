#include <assert.h>
#include <string.h>
void func0(int* game, int* guess, int* out, int length);

int issame(int* a, int* b, int length) {
    for (int i = 0; i < length; i++) {
        if (a[i] != b[i]) return 0;
    }
    return 1;
}

int main() {
    int result[6];

    func0((int[]){1,2,3,4,5,1}, (int[]){1,2,3,4,2,-2}, result, 6);
    assert(issame(result, (int[]){0,0,0,0,3,3}, 6));

    func0((int[]){0,5,0,0,0,4}, (int[]){4,1,1,0,0,-2}, result, 6);
    assert(issame(result, (int[]){4,4,1,0,0,6}, 6));

    func0((int[]){1,2,3,4,5,1}, (int[]){1,2,3,4,2,-2}, result, 6);
    assert(issame(result, (int[]){0,0,0,0,3,3}, 6));

    func0((int[]){0,0,0,0,0,0}, (int[]){0,0,0,0,0,0}, result, 6);
    assert(issame(result, (int[]){0,0,0,0,0,0}, 6));

    func0((int[]){1,2,3}, (int[]){-1,-2,-3}, result, 3);
    assert(issame(result, (int[]){2,4,6}, 3));

    func0((int[]){1,2,3,5}, (int[]){-1,2,3,4}, result, 4);
    assert(issame(result, (int[]){2,0,0,1}, 4));

    return 0;
}

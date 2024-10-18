#include <assert.h>
void func0(int number, int need, int remaining, int result[2]);

int issame(int a[2], int b[2]) {
    return a[0] == b[0] && a[1] == b[1];
}

int main() {
    int result[2];

    func0(5, 6, 10, result);
    assert(issame(result, (int[]){11, 4}));

    func0(4, 8, 9, result);
    assert(issame(result, (int[]){12, 1}));

    func0(1, 10, 10, result);
    assert(issame(result, (int[]){11, 0}));

    func0(2, 11, 5, result);
    assert(issame(result, (int[]){7, 0}));

    func0(4, 5, 7, result);
    assert(issame(result, (int[]){9, 2}));

    func0(4, 5, 1, result);
    assert(issame(result, (int[]){5, 0}));
    
    return 0;
}

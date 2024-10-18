#include <stdio.h>
#include <assert.h>
void func0(int *l, int size);

int issame(int *a, int size_a, int *b, int size_b) {
    if (size_a != size_b) return 0;
    for (int i = 0; i < size_a; i++) {
        if (a[i] != b[i]) return 0;
    }
    return 1;
}

int main() {
    int list1[] = {};
    int result1[] = {};
    func0(list1, 0);
    assert(issame(list1, 0, result1, 0));

    int list2[] = {3, 2, 1};
    int result2[] = {4, 3, 2};
    func0(list2, 3);
    assert(issame(list2, 3, result2, 3));

    int list3[] = {5, 2, 5, 2, 3, 3, 9, 0, 123};
    int result3[] = {6, 3, 6, 3, 4, 4, 10, 1, 124};
    func0(list3, 9);
    assert(issame(list3, 9, result3, 9));

    return 0;
}

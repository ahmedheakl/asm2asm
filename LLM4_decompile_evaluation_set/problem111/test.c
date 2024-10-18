#include <assert.h>
#include <string.h>
const char* func0(int *lst1, int size1, int *lst2, int size2);

int main() {
    assert(strcmp(func0((int[]){1, 2, 3, 4}, 4, (int[]){1, 2, 3, 4}, 4), "YES") == 0);
    assert(strcmp(func0((int[]){1, 2, 3, 4}, 4, (int[]){1, 5, 3, 4}, 4), "NO") == 0);
    assert(strcmp(func0((int[]){1, 2, 3, 4}, 4, (int[]){2, 1, 4, 3}, 4), "YES") == 0);
    assert(strcmp(func0((int[]){5, 7, 3}, 3, (int[]){2, 6, 4}, 3), "YES") == 0);
    assert(strcmp(func0((int[]){5, 7, 3}, 3, (int[]){2, 6, 3}, 3), "NO") == 0);
    assert(strcmp(func0((int[]){3, 2, 6, 1, 8, 9}, 6, (int[]){3, 5, 5, 1, 1, 1}, 6), "NO") == 0);
    assert(strcmp(func0((int[]){100, 200}, 2, (int[]){200, 200}, 2), "YES") == 0);

    return 0;
}

#include <assert.h>
#include <stdbool.h>
int* func0(int n);

int main() {
    int* result;
    int test1[] = {3, 5, 7};
    int test2[] = {4, 6, 8, 10};
    int test3[] = {5, 7, 9, 11, 13};
    int test4[] = {6, 8, 10, 12, 14, 16};
    int test5[] = {8, 10, 12, 14, 16, 18, 20, 22};

    result = func0(3);
    for (int i = 0; i < 3; i++) assert(result[i] == test1[i]);
    free(result);

    result = func0(4);
    for (int i = 0; i < 4; i++) assert(result[i] == test2[i]);
    free(result);

    result = func0(5);
    for (int i = 0; i < 5; i++) assert(result[i] == test3[i]);
    free(result);

    result = func0(6);
    for (int i = 0; i < 6; i++) assert(result[i] == test4[i]);
    free(result);

    result = func0(8);
    for (int i = 0; i < 8; i++) assert(result[i] == test5[i]);
    free(result);

    return 0;
}

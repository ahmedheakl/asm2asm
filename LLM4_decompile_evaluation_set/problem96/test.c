#include <assert.h>
#include <stddef.h>
int func0(char* dict[][2], int size);

int main() {
    char* test1[][2] = {{"p","pineapple"}, {"b","banana"}};
    assert(func0(test1, 2) == 1);

    char* test2[][2] = {{"p","pineapple"}, {"A","banana"}, {"B","banana"}};
    assert(func0(test2, 3) == 0);

    char* test3[][2] = {{"p","pineapple"}, {"5","banana"}, {"a","apple"}};
    assert(func0(test3, 3) == 0);

    char* test4[][2] = {{"Name","John"}, {"Age","36"}, {"City","Houston"}};
    assert(func0(test4, 3) == 0);

    char* test5[][2] = {{"STATE","NC"}, {"ZIP","12345"}};
    assert(func0(test5, 2) == 1);

    char* test6[][2] = {{"fruit","Orange"}, {"taste","Sweet"}};
    assert(func0(test6, 2) == 1);

    assert(func0(NULL, 0) == 0);

    return 0;
}

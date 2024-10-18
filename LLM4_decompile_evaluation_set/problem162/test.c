#include <assert.h>
#include <string.h>
char* func0(char *s);

int main(){
    char test1[] = "AsDf";
    assert(strcmp(func0(test1), "aSdF") == 0);

    char test2[] = "1234";
    assert(strcmp(func0(test2), "4321") == 0);

    char test3[] = "ab";
    assert(strcmp(func0(test3), "AB") == 0);

    char test4[] = "#a@C";
    assert(strcmp(func0(test4), "#A@c") == 0);

    char test5[] = "#AsdfW^45";
    assert(strcmp(func0(test5), "#aSDFw^45") == 0);

    char test6[] = "#6@2";
    assert(strcmp(func0(test6), "2@6#") == 0);

    char test7[] = "#$a^D";
    assert(strcmp(func0(test7), "#$A^d") == 0);

    char test8[] = "#ccc";
    assert(strcmp(func0(test8), "#CCC") == 0);

    return 0;
}

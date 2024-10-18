#include <stdio.h>
#include <assert.h>
#include <string.h>
void func0(char *text);

int main() {
    char test1[] = "";
    func0(test1);
    assert(strcmp(test1, "") == 0);
    
    char test2[] = "abcdef\nghijklm";
    func0(test2);
    assert(strcmp(test2, "bcdf\nghjklm") == 0);
    
    char test3[] = "fedcba";
    func0(test3);
    assert(strcmp(test3, "fdcb") == 0);
    
    char test4[] = "eeeee";
    func0(test4);
    assert(strcmp(test4, "") == 0);
    
    char test5[] = "acBAA";
    func0(test5);
    assert(strcmp(test5, "cB") == 0);
    
    char test6[] = "EcBOO";
    func0(test6);
    assert(strcmp(test6, "cB") == 0);
    
    char test7[] = "ybcd";
    func0(test7);
    assert(strcmp(test7, "ybcd") == 0);

    return 0;
}

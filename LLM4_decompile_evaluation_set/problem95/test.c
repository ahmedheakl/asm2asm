#include <assert.h>
int func0(int lst[], int size);

int main() {
    int lst1[] = {0,3,2,1,3,5,7,4,5,5,5,2,181,32,4,32,3,2,32,324,4,3};
    assert(func0(lst1, sizeof(lst1)/sizeof(lst1[0])) == 10);

    int lst2[] = {1,0,1,8,2,4597,2,1,3,40,1,2,1,2,4,2,5,1};
    assert(func0(lst2, sizeof(lst2)/sizeof(lst2[0])) == 25);

    int lst3[] = {1,3,1,32,5107,34,83278,109,163,23,2323,32,30,1,9,3};
    assert(func0(lst3, sizeof(lst3)/sizeof(lst3[0])) == 13);

    int lst4[] = {0,724,32,71,99,32,6,0,5,91,83,0,5,6};
    assert(func0(lst4, sizeof(lst4)/sizeof(lst4[0])) == 11);

    int lst5[] = {0,81,12,3,1,21};
    assert(func0(lst5, sizeof(lst5)/sizeof(lst5[0])) == 3);

    int lst6[] = {0,8,1,2,1,7};
    assert(func0(lst6, sizeof(lst6)/sizeof(lst6[0])) == 7);

    int lst7[] = {8191};
    assert(func0(lst7, sizeof(lst7)/sizeof(lst7[0])) == 19);

    int lst8[] = {8191, 123456, 127, 7};
    assert(func0(lst8, sizeof(lst8)/sizeof(lst8[0])) == 19);

    int lst9[] = {127, 97, 8192};
    assert(func0(lst9, sizeof(lst9)/sizeof(lst9[0])) == 10);

    return 0;
}

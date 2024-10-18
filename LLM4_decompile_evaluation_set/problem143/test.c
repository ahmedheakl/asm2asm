#include <assert.h>
int func0(int* lst, int size);

int main() {
    {
        int lst[] = {1, 2, 3};
        assert(func0(lst, sizeof(lst)/sizeof(lst[0])) == 6);
    }
    {
        int lst[] = {1, 4, 9};
        assert(func0(lst, sizeof(lst)/sizeof(lst[0])) == 14);
    }
    {
        int lst[] = {};
        assert(func0(lst, sizeof(lst)/sizeof(lst[0])) == 0);
    }
    {
        int lst[] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
        assert(func0(lst, sizeof(lst)/sizeof(lst[0])) == 9);
    }
    {
        int lst[] = {-1, -1, -1, -1, -1, -1, -1, -1, -1};
        assert(func0(lst, sizeof(lst)/sizeof(lst[0])) == -3);
    }
    {
        int lst[] = {0};
        assert(func0(lst, sizeof(lst)/sizeof(lst[0])) == 0);
    }
    {
        int lst[] = {-1, -5, 2, -1, -5};
        assert(func0(lst, sizeof(lst)/sizeof(lst[0])) == -126);
    }
    {
        int lst[] = {-56, -99, 1, 0, -2};
        assert(func0(lst, sizeof(lst)/sizeof(lst[0])) == 3030);
    }
    {
        int lst[] = {-1, 0, 0, 0, 0, 0, 0, 0, -1};
        assert(func0(lst, sizeof(lst)/sizeof(lst[0])) == 0);
    }
    {
        int lst[] = {-16, -9, -2, 36, 36, 26, -20, 25, -40, 20, -4, 12, -26, 35, 37};
        assert(func0(lst, sizeof(lst)/sizeof(lst[0])) == -14196);
    }
    {
        int lst[] = {-1, -3, 17, -1, -15, 13, -1, 14, -14, -12, -5, 14, -14, 6, 13, 11, 16, 16, 4, 10};
        assert(func0(lst, sizeof(lst)/sizeof(lst[0])) == -1448);
    }

    return 0;
}

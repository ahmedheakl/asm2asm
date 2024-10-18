#include <assert.h>
long long func0(long long *nums, int size);

int main() {
    long long nums1[] = {2, 3, 4, 1, 2, 4};
    assert(func0(nums1, 6) == 1);

    long long nums2[] = {-1, -2, -3};
    assert(func0(nums2, 3) == -6);

    long long nums3[] = {-1, -2, -3, 2, -10};
    assert(func0(nums3, 5) == -14);

    long long nums4[] = {-9999999999999999};
    assert(func0(nums4, 1) == -9999999999999999);

    long long nums5[] = {0, 10, 20, 1000000};
    assert(func0(nums5, 4) == 0);

    long long nums6[] = {-1, -2, -3, 10, -5};
    assert(func0(nums6, 5) == -6);

    long long nums7[] = {100, -1, -2, -3, 10, -5};
    assert(func0(nums7, 6) == -6);

    long long nums8[] = {10, 11, 13, 8, 3, 4};
    assert(func0(nums8, 6) == 3);

    long long nums9[] = {100, -33, 32, -1, 0, -2};
    assert(func0(nums9, 6) == -33);

    long long nums10[] = {-10};
    assert(func0(nums10, 1) == -10);

    long long nums11[] = {7};
    assert(func0(nums11, 1) == 7);

    long long nums12[] = {1, -1};
    assert(func0(nums12, 2) == -1);

    return 0;
}

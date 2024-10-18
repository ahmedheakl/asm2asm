#include <assert.h>
int func0(int nums[], int size);

int main() {
    {
        int nums[] = {5, -2, 1, -5};
        assert(func0(nums, sizeof(nums) / sizeof(nums[0])) == 0);
    }

    {
        int nums[] = {15, -73, 14, -15};
        assert(func0(nums, sizeof(nums) / sizeof(nums[0])) == 1);
    }

    {
        int nums[] = {33, -2, -3, 45, 21, 109};
        assert(func0(nums, sizeof(nums) / sizeof(nums[0])) == 2);
    }

    {
        int nums[] = {43, -12, 93, 125, 121, 109};
        assert(func0(nums, sizeof(nums) / sizeof(nums[0])) == 4);
    }

    {
        int nums[] = {71, -2, -33, 75, 21, 19};
        assert(func0(nums, sizeof(nums) / sizeof(nums[0])) == 3);
    }

    {
        int nums[] = {1};
        assert(func0(nums, sizeof(nums) / sizeof(nums[0])) == 0);
    }

    {
        int nums[] = {};
        assert(func0(nums, sizeof(nums) / sizeof(nums[0])) == 0);
    }

    return 0;
}

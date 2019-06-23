#include <stdio.h>
#include <stdlib.h>



int maxProduct(int* nums, int numsSize)
{
    if (numsSize == 0)
        return 0;
    if (numsSize == 1)
        return nums[0];

    int g_max = nums[0];
    int l_max = 1;
    int l_min = 1;

    int idx = 0;
    while (idx < numsSize) {
        if (nums[idx] > 0) {
            if ((nums[idx] * l_max) < l_max)
                l_max = nums[idx];
            else
                l_max *= nums[idx];
            l_min *= nums[idx];
        } else if (nums[idx] < 0) {
            if ((nums[idx] * l_min) > l_min) {
                int temp = l_max;
                l_max = l_min * nums[idx];
                if ((temp * nums[idx]) < nums[idx])
                    l_min = temp * nums[idx];
                else
                    l_min = nums[idx];
            } else {
                l_max *= nums[idx];
                l_min *= nums[idx];
            }
        } else {
            if (nums[idx] > g_max)
                g_max = nums[idx];
            if (idx < (numsSize - 1)) {
                idx++;
                l_max = nums[idx];
                l_min = nums[idx];
            }
        }

        if (l_max > g_max)
            g_max = l_max;

        idx++;
    }

    return g_max;
}



int main()
{
    int arr[] = {0,-3,1,1};
    int ans = maxProduct(arr, 4);
    printf("%d\n", ans);
    return 0;
}
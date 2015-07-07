int maxSubArray(int* nums, int numsSize)
{
    if (numsSize == 0)
        return 0;

    int g_max = nums[0];
    int l_max = nums[0];
    int idx = 1;
    while (idx < numsSize) {
        if ((nums[idx] + l_max) < nums[idx])
            l_max = nums[idx];
        else
            l_max += nums[idx];

        if (l_max > g_max)
            g_max = l_max;

        idx++;
    }

    return g_max;
}
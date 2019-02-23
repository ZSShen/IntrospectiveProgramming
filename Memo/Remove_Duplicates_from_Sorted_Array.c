int removeDuplicates(int* nums, int numsSize)
{
    if (numsSize == 0)
        return 0;
    if (numsSize == 1)
        return 1;

    int idx_bgn = 0;
    int idx_end = 1;
    while (idx_end < numsSize) {
        if (nums[idx_bgn] == nums[idx_end])
            idx_end++;
        else
            nums[++idx_bgn] = nums[idx_end++];
    }

    return idx_bgn + 1;
}
#define NIL (-2147483647)


int removeElement(int* nums, int numsSize, int val)
{
    if (!nums)
        return numsSize;

    int pivot = numsSize - 1;
    int idx = numsSize - 1;
    int temp;
    while (idx >= 0) {
        if (nums[idx] == val) {
            temp = nums[pivot];
            nums[pivot] = nums[idx];
            nums[idx] = temp;
            pivot--;
        }
        idx--;
    }

    return pivot + 1;
}
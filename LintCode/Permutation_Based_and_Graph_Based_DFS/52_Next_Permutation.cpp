class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers
     */
    vector<int> nextPermutation(vector<int> &nums) {
        // write your code here

        int size = nums.size();
        if (size == 0) {
            return nums;
        }

        int i = size - 1;
        while (i > 0 && nums[i - 1] >= nums[i]) {
            --i;
        }

        if (i == 0) {
            swapElements(nums, 0, size - 1);
            return nums;
        }

        int j = size - 1;
        while (j > i && nums[j] <= nums[i - 1]) {
            --j;
        }

        std::swap(nums[j], nums[i - 1]);
        swapElements(nums, i, size - 1);
        return nums;
    }

private:
    void swapElements(std::vector<int>& nums, int bgn, int end) {
        while (bgn < end) {
            std::swap(nums[bgn], nums[end]);
            ++bgn;
            --end;
        }
    }
};
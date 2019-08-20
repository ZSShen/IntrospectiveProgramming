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


class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers
     */
    vector<int> nextPermutation(vector<int> &nums) {
        // write your code here

        int n = nums.size();
        if (n <= 1) {
            return nums;
        }

        // Example: 1 3 6 5 4 2

        int i = n - 1;
        while (i > 0 && nums[i - 1] >= nums[i]) {
            --i;
        }

        if (i == 0) {
            // We already have the maximum permutation, so the next one is
            // the minimum permutation.
            swapSegment(nums, 0, n - 1);
            return nums;
        }

        //   * <= turning point
        // 1 3 6 5 4 2

        int j = n - 1;
        while (j > i && nums[j] <= nums[i - 1]) {
            --j;
        }

        //         * <= the next greater element
        // 1 3 6 5 4 2

        std::swap(nums[i - 1], nums[j]);

        // 1 4 6 5 3 2
        //     * * * * <= sorted in descending order.

        swapSegment(nums, i, n - 1);

        // 1 4 2 3 5 6
        //     * * * * <= now sorted in ascending order.

        return nums;
    }

private:
    void swapSegment(std::vector<int>& nums, int bgn, int end) {

        while (bgn < end) {
            std::swap(nums[bgn], nums[end]);
            ++bgn;
            --end;
        }
    }
};

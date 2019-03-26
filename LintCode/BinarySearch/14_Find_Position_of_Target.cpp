class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target to find.
     * @return: The first position of target. Position starts from 0.
     */
    int binarySearch(vector<int> &nums, int target) {
        // write your code here

        int size = nums.size();
        if (size == 0) {
            return -1;
        }

        int bgn = 0;
        int end = size - 1;
        while (bgn + 1 < end) {
            int mid = bgn + (end - bgn) / 2;
            if (target <= nums[mid]) {
                end = mid;
            } else {
                bgn = mid;
            }
        }

        if (nums[bgn] == target) {
            return bgn;
        }
        if (nums[end] == target) {
            return end;
        }

        return -1;
    }
};
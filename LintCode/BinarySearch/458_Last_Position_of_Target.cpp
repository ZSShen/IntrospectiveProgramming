class Solution {
public:
    /**
     * @param nums: An integer array sorted in ascending order
     * @param target: An integer
     * @return: An integer
     */
    int lastPosition(vector<int> &nums, int target) {
        // write your code here

        int size = nums.size();
        if (size == 0) {
            return -1;
        }

        int bgn = 0;
        int end = size - 1;
        while (bgn + 1 < end) {
            int mid = bgn + (end - bgn) / 2;
            if (target >= nums[mid]) {
                bgn = mid;
            } else {
                end = mid;
            }
        }

        if (nums[end] == target) {
            return end;
        }
        if (nums[bgn] == target) {
            return bgn;
        }
        return -1;
    }
};
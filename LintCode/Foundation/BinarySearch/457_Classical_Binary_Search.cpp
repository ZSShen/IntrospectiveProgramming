class Solution {
public:
    /**
     * @param nums: An integer array sorted in ascending order
     * @param target: An integer
     * @return: An integer
     */
    int findPosition(vector<int> &nums, int target) {
        // write your code here

        int size = nums.size();
        if (size == 0) {
            return -1;
        }

        int bgn = 0;
        int end = size - 1;

        while (bgn + 1 < end) {
            int mid = bgn + (end - bgn) / 2;
            if (nums[mid] == target) {
                return mid;
            }

            if (nums[mid] < target) {
                bgn = mid;
            } else {
                end = mid;
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
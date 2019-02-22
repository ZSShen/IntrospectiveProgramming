class Solution {
public:
    /**
     * @param nums: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &nums) {
        // write your code here

        int size = nums.size();
        int l = 0, r = size - 1;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (nums[l] > nums[r]) {
                if (nums[m] > nums[r]) {
                    l = m;
                } else {
                    r = m;
                }
            } else {
                if (nums[l] < nums[m]) {
                    r = m;
                } else {
                    l = m;
                }
            }
        }

        return (nums[l] < nums[r]) ? nums[l] : nums[r];
    }
};
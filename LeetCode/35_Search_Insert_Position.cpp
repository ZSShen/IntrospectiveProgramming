class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        int l = 0;
        int r = nums.size() - 1;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (nums[m] == target) {
                return m;
            }

            if (nums[m] < target) {
                l = m;
            } else {
                r = m;
            }
        }

        if (target > nums[r]) {
            return r + 1;
        }
        if (target > nums[l]) {
            return r;
        }
        return l;
    }
};
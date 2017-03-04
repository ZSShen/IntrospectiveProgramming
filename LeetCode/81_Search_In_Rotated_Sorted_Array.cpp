class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int sz = nums.size();
        if (sz == 0) {
            return false;
        }

        int l = 0, r = sz - 1;
        while (l <= r) {
            int m = (l + r) >> 1;
            if (nums[m] == target) {
                return true;
            }

            if (nums[m] < nums[r]) {
                if (target > nums[m] && target <= nums[r]) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
                continue;
            }

            if (nums[m] > nums[r]) {
                if (target < nums[m] && target >= nums[l]) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
                continue;
            }
            
            r = m - 1;
        }

        return false;
    }
};
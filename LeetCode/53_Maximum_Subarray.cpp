class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int max = nums[0];
        int local = 0;
        for (int num : nums) {
            local += num;

            if (local > max) {
                max = local;
            }

            if (local < 0) {
                local = 0;
            }
        }

        return max;
    }
};
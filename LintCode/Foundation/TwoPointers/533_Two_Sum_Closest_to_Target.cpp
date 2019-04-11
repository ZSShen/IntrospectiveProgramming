class Solution {
public:
    /**
     * @param nums: an integer array
     * @param target: An integer
     * @return: the difference between the sum and the target
     */
    int twoSumClosest(vector<int> &nums, int target) {
        // write your code here

        int ans = INT_MAX;
        int size = nums.size();
        if (size < 2) {
            return ans;
        }

        std::sort(nums.begin(), nums.end());
        
        int l = 0;
        int r = size - 1;
        while (l < r) {
            int sum = nums[l] + nums[r];
            int diff = std::abs(sum - target);
            ans = std::min(ans, diff);
            
            if (sum < target) {
                ++l;
            } else {
                --r;
            }
        }
        
        return ans;
    }
};
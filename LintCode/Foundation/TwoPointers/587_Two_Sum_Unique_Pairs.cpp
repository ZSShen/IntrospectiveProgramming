class Solution {
public:
    /**
     * @param nums: an array of integer
     * @param target: An integer
     * @return: An integer
     */
    int twoSum6(vector<int> &nums, int target) {
        // write your code here
        
        int count = 0;
        int size = nums.size();
        if (size <= 1) {
            return count;
        }

        std::sort(nums.begin(), nums.end());

        int l = 0;
        int r = size - 1;
        while (l < r) {
            int sum = nums[l] + nums[r];
            if (sum == target) {
                ++count;
                
                // Dedup
                while (l < r && nums[l] == nums[l + 1]) {
                    ++l;
                }
                while (l < r && nums[r] == nums[r - 1]) {
                    --r;
                }
                
                ++l;
                --r;
                continue;
            }
            
            if (sum > target) {
                --r;
            } else {
                ++l;
            }
        }

        return count;
    }
};

class Solution {
public:
    /**
     * @param nums: an array of integer
     * @param target: An integer
     * @return: an integer
     */
    int twoSum2(vector<int> &nums, int target) {
        // write your code here
        
        int size = nums.size();
        if (size == 0) {
            return 0;
        }

        int count = 0;
        std::sort(nums.begin(), nums.end());

        int l = 0;
        int r = size - 1;
        while (l < r) {
            if (nums[l] + nums[r] > target) {
                count += r - l;
                --r;
            } else {
                ++l;
            }
        }

        return count;
    }
};
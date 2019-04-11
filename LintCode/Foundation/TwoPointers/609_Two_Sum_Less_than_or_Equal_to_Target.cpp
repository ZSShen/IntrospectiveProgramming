class Solution {
public:
    /**
     * @param nums: an array of integer
     * @param target: an integer
     * @return: an integer
     */
    int twoSum5(vector<int> &nums, int target) {
        // write your code here

        int count = 0;
        int size = nums.size();
        if (size == 0) {
            return count;
        }

        std::sort(nums.begin(), nums.end());

        int l = 0;
        int r = size - 1;

        while (l < r) {
            if (nums[l] + nums[r] <= target) {
                count += r - l;
                ++l;
            } else {
                --r;
            }
        }

        return count;        
    }
};
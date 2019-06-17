class Solution {
public:
    /**
     * @param nums: an array of integer
     * @param target: an integer
     * @return: an integer
     */
    int twoSum5(vector<int> &nums, int target) {
        // write your code here

        /**
         *     l       r
         *  2, 7, 11, 15
         *
         *  (l + 1)
         */

        std::sort(nums.begin(), nums.end());

        int n = nums.size();
        int count = 0;

        for (int r = 1 ; r < n ; ++r) {
            for (int l = r - 1 ; l >= 0 ; --l) {
                if (nums[r] + nums[l] <= target) {
                    count += l + 1;
                    break;
                }
            }
        }

        return count;
    }
};
class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: nothing
     */
    void wiggleSort(vector<int> &nums) {
        // write your code here

        /**
         * [3, 5, 2, 1, 6, 4]
         *
         * If i is even, num[i] <= num[i - 1].
         * If i is odd,  num[i] >= num[i - 1].
         *
         */

        int n = nums.size();

        for (int i = 1 ; i < n ; ++i) {
            if ((i & 1) == 0) {
                if (nums[i] > nums[i - 1]) {
                    std::swap(nums[i], nums[i - 1]);
                }
                continue;
            } else {
                if (nums[i] < nums[i - 1]) {
                    std::swap(nums[i], nums[i - 1]);
                }
                continue;
            }
        }
    }
};

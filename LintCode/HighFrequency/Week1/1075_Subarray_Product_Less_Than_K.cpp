class Solution {
public:
    /**
     * @param nums: an array
     * @param k: an integer
     * @return: the number of subarrays where the product of all the elements in the subarray is less than k
     */
    int numSubarrayProductLessThanK(vector<int> &nums, int k) {
        // Write your code here

        int len = nums.size();
        if (len == 0) {
            return 0;
        }

        int count = 0;
        for (int i = 0 ; i < len ; ++i) {
            int product = 1;
            for (int j = i ; j >= 0 ; --j) {
                product *= nums[j];
                if (product >= k) {
                    break;
                }
                ++count;
            }
        }

        return count;
    }
};
class Solution {
public:
    /**
     * @param nums: an array
     * @param k: an integer
     * @return: the number of subarrays where the product of all the elements in the subarray is less than k
     */
    int numSubarrayProductLessThanK(vector<int> &nums, int k) {
        // Write your code here

        int n = nums.size();
        if (n == 0) {
            return 0;
        }

        int count = 0;
        int res = 1;
        int l = 0;

        for (int r = 0 ; r < n ; ++r) {
            res *= nums[r];

            while (res >= k && l <= r) {
                res /= nums[l];
                ++l;
            }

            count += r - l + 1;
        }

        return count;
    }
};
class Solution {
public:
    /**
     * @param nums: an array
     * @param k: a target value
     * @return: the maximum length of a subarray that sums to k
     */
    int maxSubArrayLen(vector<int> &nums, int k) {
        // Write your code here

        /**
         *   1  -1  5  -2  3
         *   1   0  5   3  6
         *
         *  -2  -1  2   1
         *  -2  -3  -1  0
         *
         *  HashTable(Key = Prefix Sum) = (Value = Index)
         */

        int n = nums.size();
        int sum = 0;
        int ans = INT_MIN;
        std::unordered_map<int, int> map;

        for (int i = 0 ; i < n ; ++i) {

            sum += nums[i];
            if (sum == k) {
                ans = i + 1;
            } else if (map.count(sum - k) == 1) {
                ans = std::max(ans, i - map[sum - k]);
            }

            if (map.count(sum) == 0) {
                map[sum] = i;
            }
        }

        return (ans != INT_MIN) ? ans : 0;
    }
};
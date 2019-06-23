class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An integer
     */
    int maxProduct(vector<int> &nums) {
        // write your code here

        /**
         * dp_m[i]: The minimum value we can collect till the ith round.
         * dp_M[i]: The maximum value we can collect till the ith round.
         *
         * dp_m[i] = MIN{num * dp_m[i - 1], num * dp_M[i - 1], num}
         * dp_M[i] = MAX{num * dp_m[i - 1], num * dp_M[i - 1], num}
         */

        if (nums.empty()) {
            return 0;
        }

        int max_sofar = 1;
        int min_sofar = 1;
        int ans = nums[0];

        for (int num : nums) {
            int max_curr =
                std::max(std::max(num * min_sofar, num * max_sofar), num);
            int min_curr =
                std::min(std::min(num * min_sofar, num * max_sofar), num);

            ans = std::max(ans, max_curr);

            max_sofar = max_curr;
            min_sofar = min_curr;
        }

        return ans;
    }
};
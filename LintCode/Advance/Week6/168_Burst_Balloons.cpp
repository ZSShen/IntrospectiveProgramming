class Solution {
public:
    /**
     * @param nums: A list of integer
     * @return: An integer, maximum coins
     */
    int maxCoins(vector<int> &nums) {
        // write your code here

        /**
         * Range(i, j)
         * k is the latest balloon among the range that we burst.
         *
         * dp[i][j]: The max value we can secure from bursting the balloons
         *           among the range (i, j).
         *
         * dp[i][j] =  Max | dp[i][k - 1] + dp[k + 1][j] + N[i - 1] * N[k] * N[j + 1]
         *            i<=k<=j
         */

        int n = nums.size();

        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        int dp[n + 2][n + 2] = {{0}};

        for (int l = 1 ; l <= n ; ++l) {
            for (int i = 1, j = i + l - 1 ; i <= n - l + 1 ; ++i, ++j) {
                for (int k = i ; k <= j ; ++k) {
                    dp[i][j] = std::max(dp[i][j],
                        dp[i][k - 1] + dp[k + 1][j] +  nums[i - 1] * nums[k] * nums[j + 1]);
                }
            }
        }

        return dp[1][n];
    }
};
class Solution {
public:
    Solution()
      : max(std::numeric_limits<int>::max())
    { }

    /**
     * @param triangle: a list of lists of integers
     * @return: An integer, minimum path sum
     */
    int minimumTotal(vector<vector<int>> &triangle) {
        // write your code here

        /**
         * dp[i][j]: The min path sum starting from the root node to the
         *           jth cell of the ith row.
         *
         * dp[i][j] = MIN{dp[i - 1][j], dp[i - 1][j - 1]} + values[i][j]
         */

        int level = triangle.size();
        if (level == 0) {
            return 0;
        }

        std::vector<std::vector<int>> dp(level);
        dp[0].resize(1);
        dp[0][0] = triangle[0][0];

        for (int i = 1 ; i < level ; ++i) {

            int size = i + 1;
            dp[i].resize(size);

            for (int j = 0 ; j < size ; ++j) {

                int opt = max;
                if (j - 1 >= 0) {
                    opt = std::min(opt, dp[i - 1][j - 1]);
                }
                if (j <= size - 2) {
                    opt = std::min(opt, dp[i - 1][j]);
                }

                dp[i][j] = opt + triangle[i][j];
            }
        }

        int ans = max;
        for (int i = 0 ; i < level ; ++i) {
            ans = std::min(ans, dp[level - 1][i]);
        }

        return ans;
    }

private:
    int max;
};
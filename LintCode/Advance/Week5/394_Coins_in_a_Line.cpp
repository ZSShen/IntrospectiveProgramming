class Solution {
public:
    /**
     * @param n: An integer
     * @return: A boolean which equals to true if the first player will win
     */
    bool firstWillWin(int n) {
        // write your code here

        /**
         *              4(L)
         *            /   \
         *       (W)3       2(W)
         *        /   \   /   \
         *   (W)2       11     0(L)
         *    /   \   (W)(W)
         *  1(W)   0(L)
         *
         *
         *  dp[i]: Whether a person is winable when there are i coins remained.
         *
         *  dp[i] = dp[i - 1] == false || dp[i - 2] == false
         *
         *  dp[0] = false
         *  dp[1] = true
         *  dp[2] = true
         *
         */

        if (n == 0) {
            return false;
        }
        if (n == 1 || n == 2) {
            return true;
        }

        std::vector<bool> dp(3, false);
        dp[0] = false;
        dp[1] = true;
        dp[2] = true;

        for (int i = 3 ; i <= n ; ++i) {
            dp[i % 3] = dp[(i - 1) % 3] == false || dp[(i - 2) % 3] == false;
        }

        return dp[n % 3];
    }
};
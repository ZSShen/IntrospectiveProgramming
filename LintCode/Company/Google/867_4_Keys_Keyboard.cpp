class Solution {
public:
    /**
     * @param N: an integer
     * @return: return an integer
     */
    int maxA(int N) {
        // write your code here

        /**
         * dp[i]: The maximum number of letters we can get after pressing
         *        i times of keys.
         *
         *
         * dp[i] = MAX | dp[i - 1] + 1
         *             | MAX { dp[j] * (i - j - 1) | 0 <= j <= i - 3 }
         *
         */

        std::vector<int> dp(N);
        dp[0] = 1;

        for (int i = 1 ; i < N ; ++i) {
            dp[i] = dp[i - 1] + 1;
            for (int j = 0 ; j <= i - 3 ; ++j) {
                dp[i] = std::max(dp[i], dp[j] * (i - j - 1));
            }
        }

        return dp[N - 1];
    }
};
class Solution {
public:
    /**
     * @param A: An array of non-negative integers
     * @return: The maximum amount of money you can rob tonight
     */
    long long houseRobber(vector<int> &A) {
        // write your code here

        /**
         *
         *  dp[i] = Max| price[i] + dp[i - 2]
         *             | dp[i - 1]
         *
         *  dp[0] = price[0]
         *  dp[1] = Max(price[0], price[1])
         */

        int size = A.size();
        if (size == 0) {
            return 0;
        }

        std::vector<long long> dp(size);
        dp[0] = A[0];
        dp[1] = std::max(A[0], A[1]);

        for (int i = 2 ; i < size ; ++i) {
            dp[i] = std::max(A[i] + dp[i - 2], dp[i - 1]);
        }

        return dp[size - 1];
    }
};
class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: An integer
     */
    int jump(vector<int> &A) {
        // write your code here

        int n = A.size();

        std::vector<int> dp(n, INT_MAX);
        dp[0] = 0;

        for (int i = 0 ; i < n ; ++i) {
            if (dp[i] == INT_MAX) {
                break;
            }

            int step = dp[i] + 1;
            int max = std::min(A[i], n - i - 1);

            for (int j = 1 ; j <= max ; ++j) {
                dp[i + j] = std::min(dp[i + j], step);
            }
        }

        return dp[n - 1];
    }
};
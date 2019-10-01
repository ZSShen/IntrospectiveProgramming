class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: A boolean
     */
    bool canJump(vector<int> &A) {
        // write your code here

        int n = A.size();

        std::vector<bool> dp(n, false);
        dp[0] = true;

        for (int i = 0 ; i < n ; ++i) {
            if (!dp[i]) {
                break;
            }

            int max = std::min(A[i], n - i - 1);
            for (int j = 1 ; j <= max ; ++j) {
                dp[i + j] = true;
            }
        }

        return dp[n - 1];
    }
};
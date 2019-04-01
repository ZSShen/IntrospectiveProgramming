class Solution {
public:
    /**
     * @param n: An integer
     * @return: return a  integer as description.
     */
    int nthUglyNumber(int n) {
        // write your code here

        std::vector<int> dp;
        dp.push_back(1);

        int i = 0, j = 0, k = 0;
        for (int r = 2 ; r <= n ; ++r) {
            int num_i = dp[i] * 2;
            int num_j = dp[j] * 3;
            int num_k = dp[k] * 5;

            int min = std::min(std::min(num_i, num_j), num_k);
            dp.push_back(min);
            if (min == num_i) {
                ++i;
            }
            if (min == num_j) {
                ++j;
            }
            if (min == num_k) {
                ++k;
            }
        }

        return dp[n - 1];
    }
};
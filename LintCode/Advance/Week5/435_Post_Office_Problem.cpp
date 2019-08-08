class Solution {
public:
    /**
     * @param A: an integer array
     * @param k: An integer
     * @return: an integer
     */
    int postOffice(vector<int> &A, int k) {
        // write your code here

        /**
         * dp[i][j]: The min sum distance of buidling i post offices
         *           for the first j houses.
         *
         * cost[i][j]: The min sum distance to build a post office to
         *             serve the houses from i to j.
         *
         * From i to j, build the post at the middle point can help to minimize
         * the cost.
         *
         * dp[i][j] =  MIN {dp[i - 1][k] + cost[k + 1][j]}
         *           i-1<=k<j
         */

        int n = A.size();
        if (n == 0 || k == 0) {
            return 0;
        }

        std::sort(A.begin(), A.end());

        std::vector<std::vector<int>> cost(n, std::vector<int>(n, 0));
        for (int i = 0 ; i < n - 1 ; ++i) {
            for (int j = i + 1 ; j < n ; ++j) {
                int m = (i + j) / 2;
                int sum = 0;
                for (int h = i ; h <= j ; ++h) {
                    sum += std::abs(A[h] - A[m]);
                }
                cost[i][j] = sum;
            }
        }

        std::vector<std::vector<int>> dp(k, std::vector<int>(n, 0));
        for (int i = 0 ; i < n ; ++i) {
            dp[0][i] = cost[0][i];
        }

        for (int i = 1 ; i < k ; ++i) {
            for (int j = i ; j < n ; ++j) {

                int min = INT_MAX;
                for (int h = i - 1 ; h < j ; ++h) {
                    min = std::min(min, dp[i - 1][h] + cost[h + 1][j]);
                }
                dp[i][j] = min;
            }
        }

        return dp[k - 1][n - 1];
    }
};


class Solution {
public:
    /**
     * @param A: an integer array
     * @param k: An integer
     * @return: an integer
     */
    int postOffice(vector<int> &A, int k) {
        // write your code here

        /**
         * dp[i][j]: The minimum cost to build i post offices to serve the first
         *           j houses -- the first house to the jth house.
         *
         * cost[i][j]: The minimum cost to build a post office to serve the
         *             ith house to the jth house.
         *
         * dp[i][j] =     MIN   {dp[i - 1][k] + cost[k + 1][j]}
         *            (i-1)<=k<j
         */

        int n = A.size();
        if (n == 0 || k == 0) {
            return 0;
        }

        // We need to scan the office and house indices in ascending order.
        std::sort(A.begin(), A.end());

        std::vector<std::vector<int>> cost(n, std::vector<int>(n, 0));

        // An optimal way to build an office to serve the houses within a given
        // range is to put that office at the middle point of the range.
        for (int i = 0 ; i < n - 1 ; ++i) {
            for (int j = i + 1 ; j < n ; ++j) {
                int mid = (i + j) / 2;
                int sum = 0;
                for (int h = i ; h <= j ; ++h) {
                    sum += std::abs(A[h] - A[mid]);
                }
                cost[i][j] = sum;
            }
        }

        std::vector<std::vector<int>> dp(k, std::vector<int>(n, 0));

        // Build an office to serve the first i houses.
        for (int i = 0 ; i < n ; ++i) {
            dp[0][i] = cost[0][i];
        }

        for (int i = 1 ; i < k ; ++i) {
            for (int j = i ; j < n ; ++j) {
                int min = INT_MAX;
                for (int h = i - 1 ; h < j ; ++h) {
                    min = std::min(min, dp[i - 1][h] + cost[h + 1][j]);
                }
                dp[i][j] = min;
            }
        }

        return dp[k - 1][n - 1];
    }
};

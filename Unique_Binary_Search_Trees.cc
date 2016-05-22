class Solution
{
public:
    int numTrees(int n)
    {
        //
        // Let i denote the index of the left-most node.
        //     j denote the index of the right-most node.
        //
        // Let dp[i][j] denote the number of combinations for the
        //     the tree nodes ranging from node i to node j.
        //
        // Recursive Function:
        // dp[i][j] =  SIGMA {dp[i][k - 1] * dp[k + 1][j]}
        //            i<=k<=j
        //              if k - 1 < i, dp[i][k - 1] = 1.
        //              if k + 1 > j, dp[k + 1][j] = 1.

        if (n <= 2)
            return n;

        int dp[n][n];
        for (int i = 0 ; i < n ; ++i)
            dp[i][i] = 1;
        for (int i = 0 ; i < n - 1 ; ++i)
            dp[i][i + 1] = 2;

        for (int l = 2 ; l < n ; ++l) {
            for (int i = 0 ; i < n - l ; ++i) {
                int j = i + l;
                int sum = 0;
                for (int k = i ; k <= j ; ++k) {
                    int left = (k - 1 < i)? 1 : dp[i][k - 1];
                    int rght = (k + 1 > j)? 1 : dp[k + 1][j];
                    sum += left * rght;
                }
                dp[i][j] = sum;
            }
        }

        return dp[0][n - 1];
    }
};
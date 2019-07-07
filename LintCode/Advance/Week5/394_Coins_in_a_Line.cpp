class Solution {
public:
    /**
     * @param n: An integer
     * @return: A boolean which equals to true if the first player will win
     */
    bool firstWillWin(int n) {
        // write your code here

        /**
         *  A and B 2 competitors
         *
         *  1. If A can push B to step into a losable state, A is winnable.
         *
         *  2. No matter how hard A tries, B can always step into a winnable
         *     state. Then, A is guaranteed to lose the game.
         *
         *             4(W)
         *            / \
         *        (L)3   2(W)
         *          / \
         *      (W)2   1(W)
         *
         *  dp[i]: Whether a player is going to win the game if there are i
         *         coins in a line.
         *
         *  dp[i] = dp[i - 1] == False || dp[i - 2] == False
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


class Solution {
public:
    /**
     * @param n: An integer
     * @return: A boolean which equals to true if the first player will win
     */
    bool firstWillWin(int n) {
        // write your code here

        if (n == 0) {
            return false;
        }
        if (n == 1 || n == 2) {
            return true;
        }

        std::vector<bool> dp(n + 1, false);
        dp[1] = true;
        dp[2] = true;

        for (int i = 3 ; i <= n ; ++i) {
            dp[i] = dp[i - 1] == false || dp[i - 2] == false;
        }

        return dp[n];
    }
};
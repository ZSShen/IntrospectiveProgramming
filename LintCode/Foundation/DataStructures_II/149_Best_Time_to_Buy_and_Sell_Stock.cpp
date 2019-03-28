class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here

        int size = prices.size();
        if (size == 0) {
            return 0;
        }

        int opt = 0;
        int min = prices[0];

        for (int i = 1 ; i < size ; ++i) {
            int diff = prices[i] - min;
            opt = std::max(diff, opt);
            min = std::min(prices[i], min);
        }

        return opt;
    }
};
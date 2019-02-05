class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int size = prices.size();
        if (size <= 1) {
            return 0;
        }

        int max = 0;
        int buy = prices[0];
        for (int i = 1 ; i < size ; ++i) {
            int profit = prices[i] - buy;
            if (profit > max) {
                max = profit;
            }
            if (prices[i] < buy) {
                buy = prices[i];
            }
        }

        return max;
    }
};
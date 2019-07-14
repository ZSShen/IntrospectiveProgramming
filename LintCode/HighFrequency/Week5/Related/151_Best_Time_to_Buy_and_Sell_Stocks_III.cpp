class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here

        /**
         *  buy_1st : The maximum profits that we can get after conducting
         *            the first purchase.
         *
         *  sell_1st: The maximum profits that we can get after conducting
         *            the first selling.
         *
         *  buy_2nd : The maximum profits that we can get after conducting
         *            the second purchase.
         *
         *  sell_2nd: The maximum profits that we can get after conducting
         *            the second selling.
         *
         *
         *  price: The stock price of the ith day.
         *
         *  buy_1st  = MAX{ buy_1st, -price }
         *  sell_1st = MAX{ sell_1st, buy_1st + price}
         *  buy_2nd  = MAX{ buy_2nd, sell_1st - price }
         *  sell_2nd = MAX{ sell_2nd, buy_2nd + price }
         *  ^^^^^^^^
         */

        int buy_first = std::numeric_limits<int>::min();
        int buy_second = std::numeric_limits<int>::min();

        int sell_first = 0;
        int sell_second = 0;

        for (int price : prices) {
            buy_first = std::max(buy_first, -price);
            sell_first = std::max(sell_first, buy_first + price);

            buy_second = std::max(buy_second, sell_first - price);
            sell_second = std::max(sell_second, buy_second + price);
        }

        return sell_second;
    }
};
int maxProfit(int* prices, int pricesSize)
{
    if (pricesSize <= 1)
        return 0;

    int min = prices[0];
    int max = 0;
    int idx = 0;
    int profit;
    while (idx < pricesSize) {
        profit = prices[idx] - min;
        if (profit > max)
            max = profit;
        if (prices[idx] < min)
            min = prices[idx];
        idx++;
    }

    return max;
}
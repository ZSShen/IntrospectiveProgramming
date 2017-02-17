class Solution {
public:
    /**
     *  Simple combinatorial:
     * 
     *  f(0) = 1
     *  f(1) = 10
     *  f(2) = f(1) + 9 * 9          (for 2 digits: 10 to 99)
     *  f(3) = f(2) + 9 * 9 * 8      (for 3 digits: 100 to 999)
     *  f(4) = f(3) + 9 * 9 * 8 * 7  (for 4 digits: 1000 to 9999)
     *          ...
     */
    Solution()
        : comb_(11) {
        comb_[0] = 1;
        comb_[1] = 10;
        comb_[2] = comb_[1] + 9 * 9;

        for (int i = 3 ; i <= 10 ; ++i) {
            comb_[i] = comb_[i - 1];
            int temp = 9 * 9;
            for (int j = i - 3, k = 8 ; j >= 0 ; --j, --k) {
                temp *= k;
            }
            comb_[i] += temp;
        }
    }

    int countNumbersWithUniqueDigits(int n) {
        return (n <= 10)? comb_[n] : comb_[10];
    }

private:
    std::vector<int> comb_;
};

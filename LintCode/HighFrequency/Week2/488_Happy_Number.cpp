class Solution {
public:
    /**
     * @param n: An integer
     * @return: true if this is a happy number or false
     */
    bool isHappy(int n) {
        // write your code here

        std::unordered_set<int> set;
        while (n != 1) {
            n = decompose(n);
            if (set.count(n) == 1) {
                return false;
            }
            set.insert(n);
        }

        return true;
    }

private:
    int decompose(int n) {

        int res = 0;
        while (n > 0) {
            int digit = n % 10;
            n /= 10;
            res += digit * digit;
        }

        return res;
    }
};
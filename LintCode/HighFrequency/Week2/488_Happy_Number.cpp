class Solution {
public:
    /**
     * @param n: An integer
     * @return: true if this is a happy number or false
     */
    bool isHappy(int n) {
        // write your code here

        std::unordered_set<int> set;
        set.insert(n);

        while (n != 1) {
            n = convertNumber(n);
            if (set.count(n) == 1) {
                return false;
            }
            set.insert(n);
        }

        return true;
    }

private:
    int convertNumber(int num) {

        int res = 0;

        while (num > 0) {
            int digit = num % 10;
            res += digit * digit;
            num /= 10;
        }

        return res;
    }
};
class Solution {
public:
    /**
     * @param num: a non-negative integer
     * @return: one digit
     */
    int addDigits(int num) {
        // write your code here

        while (num >= 10) {
            num = decompose(num);
        }

        return num;
    }

private:
    int decompose(int n) {

        int res = 0;
        while (n > 0) {
            res += n % 10;
            n /= 10;
        }

        return res;
    }
};
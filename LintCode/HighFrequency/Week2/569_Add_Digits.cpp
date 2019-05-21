class Solution {
public:
    /**
     * @param num: a non-negative integer
     * @return: one digit
     */
    int addDigits(int num) {
        // write your code here

        while (num >= 10) {
            num = convertNumber(num);
        }

        return num;
    }

private:
    int convertNumber(int x) {

        int res = 0;

        while (x > 0) {
            res += x % 10;
            x /= 10;
        }

        return res;
    }
};
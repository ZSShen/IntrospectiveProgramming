class Solution {
public:
    /**
     * @param num: a positive number
     * @return: true if it's a palindrome or false
     */
    bool isPalindrome(int num) {
        // write your code here

        return num == reverse(num);
    }

private:
    int reverse(int x) {

        int res = 0;
        while (x > 0) {
            res *= 10;
            res += x % 10;
            x /= 10;
        }

        return res;
    }
};
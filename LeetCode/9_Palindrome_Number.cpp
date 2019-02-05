class Solution {
public:
    bool isPalindrome(int x) {

        if (x < 0) {
            return false;
        }

        int x_copy = x;
        int x_inv = 0;

        while (x > 0) {
            x_inv = x_inv * 10 + (x % 10);
            x /= 10;
        }

        return (x_copy == x_inv)? true : false;
    }
};
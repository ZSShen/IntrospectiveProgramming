class Solution {
public:
    /**
     * @param num: An integer
     * @return: true if num is an ugly number or false
     */
    bool isUgly(int num) {
        // write your code here

        if (num <= 0) {
            return false;
        }

        while (num > 1) {

            int div_2 = num / 2;
            if (div_2 * 2 == num) {
                num = div_2;
                continue;
            }

            int div_3 = num / 3;
            if (div_3 * 3 == num) {
                num = div_3;
                continue;
            }

            int div_5 = num / 5;
            if (div_5 * 5 == num) {
                num = div_5;
                continue;
            }

            return false;
        }

        return true;
    }
};
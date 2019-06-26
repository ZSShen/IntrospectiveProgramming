class Solution {
public:
    /**
     * @param s: the given string
     * @return: if a permutation of the string could form a palindrome
     */
    bool canPermutePalindrome(string &s) {
        // write your code here

        /**
         * Allow at most 1 char to have the odd number of occurence frequency.
         * The remained chars should have the even number of occurence frequency.
         */

        std::vector<int> freq(256, 0);

        for (char ch : s) {
            ++freq[ch - '0'];
        }

        int count = 0;
        for (int f : freq) {
            if (f % 2 == 1) {
                ++count;
                if (count == 2) {
                    return false;
                }
            }
        }

        return true;
    }
};
class Solution {
public:
    /*
     * @param chars: The letter array you should sort by Case
     * @return: nothing
     */
    void sortLetters(string &chars) {
        // write your code here

        int len = chars.length();
        if (len < 2) {
            return;
        }

        int i = 0, j = 0;
        while (j < len) {
            if (chars[j] >= 'a' && chars[j] <= 'z') {
                char temp = chars[j];
                chars[j] = chars[i];
                chars[i] = temp;
                ++i;
            }

            ++j;
        }
    }
};
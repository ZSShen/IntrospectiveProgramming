class Solution {
public:
    /**
     * @param s: a string
     * @return bool: whether you can make s a palindrome by deleting at most one character
     */
    bool validPalindrome(string &s) {
        // Write your code here
        
        int l = 0;
        int r = s.length() - 1;
        while (l < r) {
            if (s[l] == s[r]) {
                ++l;
                --r;
                continue;
            }

            return isPalindrome(s, l + 1, r) || isPalindrome(s, l, r - 1);
        }
        
        return true;
    }
    
private:
    bool isPalindrome(const std::string& str, int l, int r) {

        while (l < r) {
            if (str[l] != str[r]) {
                return false;
            }
            ++l;
            --r;
        }
        
        return true;
    }
};
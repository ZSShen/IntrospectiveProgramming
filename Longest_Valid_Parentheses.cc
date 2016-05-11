class Solution
{
public:
    int longestValidParentheses(string str)
    {
        const char* cstr = str.c_str();
        int len = str.length();
        if (len < 2)
            return 0;

        // We apply:
        // A boolean array to record the validness of each position.
        // A stack to record the last position for '(' to match ')'.
        //
        // At position i, if str[i] == '(', just temporarily mark position i
        // as invalid. Otherwise, we mark it as valid and pop the stack to get
        // the last position of '('. Then mark it as valid too.
        //
        // After string scan, we return the longest valid range as the answer.

        bool flag[len];
        stack<int> stk;

        for (int end = 0 ; end < len ; ++end) {
            if (cstr[end] == '(') {
                flag[end] = false;
                stk.push(end);
            } else {
                if (stk.empty())
                    flag[end] = false;
                else {
                    flag[end] = true;
                    int bgn = stk.top();
                    flag[bgn] = true;
                    stk.pop();
                }
            }
        }

        int max = 0, range = 0;
        for (int i = 0 ; i < len ; ++i) {
            if (flag[i])
                ++range;
            else {
                if (range > max)
                    max = range;
                range = 0;
            }
        }
        if (range > max)
            max = range;

        return max;
    }
};
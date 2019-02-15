class Solution
{
public:
    bool wordBreak(string str, unordered_set<string>& dict)
    {
        int len = str.length();

        bool dp[len + 1];
        dp[0] = true;

        // Let dp[i] represent whether the substring str(0, i - 1) can be composed
        // by the given dictionary.
        //
        // dp[i] =   OR   { dp[j] ^ IsDictWord(str(j, i)) }
        //         0<=j<i

        for (int i = 1 ; i <= len ; ++i) {
            bool match;
            for (int j = 0 ; j < i ; ++j) {
                match = dp[j] && ((dict.count(str.substr(j, i - j)) == 1)? true : false);
                if (match)
                    break;
            }
            dp[i] = match;
        }

        return dp[len];
    }
};
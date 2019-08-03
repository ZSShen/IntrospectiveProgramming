class Solution {
public:
    /**
     * @param s: a string
     * @param p: a string
     * @return: a list of index
     */
    vector<int> findAnagrams(string &s, string &p) {
        // write your code here

        int len_s = s.length();
        int len_p = p.length();
        if (len_s < len_p) {
            return {};
        }

        int freq_p[256] = {0};
        for (char ch : p) {
            ++freq_p[ch];
        }

        int count_p = 0;
        for (int i = 0 ; i < 256 ; ++i) {
            if (freq_p[i] > 0) {
                ++count_p;
            }
        }

        int freq_s[256] = {0};
        int count_s = 0;
        for (int i = 0 ; i < len_p ; ++i) {
            char ch = s[i];
            ++freq_s[ch];

            if (freq_s[ch] == freq_p[ch]) {
                ++count_s;
            }
        }

        std::vector<int> ans;
        if (count_p == count_s) {
            ans.push_back(0);
        }

        int l = 0, r = len_p - 1;
        while (r + 1 < len_s) {
            char ch = s[l];
            --freq_s[ch];
            if (freq_s[ch] == freq_p[ch] - 1) {
                --count_s;
            }
            ++l;

            ++r;
            ch = s[r];
            ++freq_s[ch];
            if (freq_s[ch] == freq_p[ch]) {
                ++count_s;
            }

            if (count_p == count_s) {
                ans.push_back(l);
            }
        }

        return ans;
    }
};


class Solution {
public:
    /**
     * @param s: a string
     * @param p: a string
     * @return: a list of index
     */
    vector<int> findAnagrams(string &s, string &p) {
        // write your code here

        // Construct the histogram of character appearance frequency for p.
        std::unordered_set<char> set;
        std::vector<int> freq_p(256, 0);
        for (char ch : p) {
            ++freq_p[ch];
            set.insert(ch);
        }

        int len_p = p.length();
        int count_p = set.size();

        // Generate the initial sliding window.
        std::vector<int> freq_s(256, 0);
        int count_s = 0;
        for (int i = 0 ; i < len_p ; ++i) {
            char ch = s[i];
            ++freq_s[ch];
            if (freq_s[ch] == freq_p[ch]) {
                ++count_s;
            }
        }

        std::vector<int> ans;

        int len_s = s.length();
        for (int i = len_p ; i <= len_s ; ++i) {

            // Compare the histograms of s and p.
            if (count_p == count_s) {
                ans.push_back(i - len_p);
            }

            if (i == len_s) {
                break;
            }

            // Adjust the sliding window.
            char ch = s[i - len_p];
            --freq_s[ch];
            if (freq_s[ch] == freq_p[ch] - 1) {
                --count_s;
            }

            ch = s[i];
            ++freq_s[ch];
            if (freq_s[ch] == freq_p[ch]) {
                ++count_s;
            }
        }

        return ans;
    }
};
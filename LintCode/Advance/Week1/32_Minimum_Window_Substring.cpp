class Solution {
public:
    /**
     * @param source : A string
     * @param target: A string
     * @return: A string denote the minimum window, return "" if there is no such a string
     */
    string minWindow(string &source , string &target) {
        // write your code here

        /**
         *                    l
         *                          r
         *  A D O B E C O D E B A N C
         *
         *  A B C
         *
         *  bag_T:  bag_S:
         *  A: 1    A: 1
         *  B: 1    B: 0
         *  C: 1    C: 1
         *
         *  T: 3
         *  S: 2    window: 4
         *
         */

        int len_s = source.size();
        int len_t = target.size();

        std::vector<int> bag_s(256, 0);
        int count_s = 0;

        std::vector<int> bag_t(256, 0);
        int count_t = 0;
        for (char ch : target) {
            ++bag_t[ch];
            if (bag_t[ch] == 1) {
                ++count_t;
            }
        }

        int l = 0, r = 0;
        int opt_size = std::numeric_limits<int>::max();
        int bgn = 0, end = -1;

        while (r < len_s) {

            char ch = source[r];
            if (bag_t[ch] == 0) {
                ++r;
                continue;
            }

            ++bag_s[ch];

            if (bag_s[ch] == bag_t[ch]) {
                ++count_s;
            }

            if (count_s == count_t) {
                do {
                    int window = r - l + 1;
                    if (window < opt_size) {
                        opt_size = window;
                        bgn = l;
                        end = r;
                    }

                    ch = source[l];
                    ++l;
                    if (bag_t[ch] == 0) {
                        continue;
                    }

                    --bag_s[ch];
                    if (bag_s[ch] < bag_t[ch]) {
                        --count_s;
                    }
                } while (count_s == count_t);
            }

            ++r;
        }

        return source.substr(bgn, end - bgn + 1);
    }
};


class Solution {
public:
    /**
     * @param source : A string
     * @param target: A string
     * @return: A string denote the minimum window, return "" if there is no such a string
     */
    string minWindow(string &source , string &target) {
        // write your code here

        /**
         *                    l
         *                          r
         *  A D O B E C O D E B A N C
         *
         *  A B C
         *
         *  bag_T:  bag_S:
         *  A: 1    A: 1
         *  B: 1    B: 0
         *  C: 1    C: 1
         *
         *  T: 3
         *  S: 2    window: 4
         *
         */

        int ns = source.length();
        if (ns == 0) {
            return "";
        }

        int nt = target.length();
        if (nt == 0) {
            return "";
        }

        std::vector<char> bag_s(256, 0);
        int count_s = 0;

        std::vector<char> bag_t(256, 0);
        int count_t = 0;
        for (int i = 0 ; i < nt ; ++i) {
            char ch = target[i];
            ++bag_t[ch];
            if (bag_t[ch] == 1) {
                ++count_t;
            }
        }

        int l = 0, r = 0;
        int min = INT_MAX, pivot;

        while (r < ns) {
            char ch = source[r];

            if (bag_t[ch] == 0) {
                ++r;
                continue;
            }

            ++bag_s[ch];
            if (bag_s[ch] == bag_t[ch]) {
                ++count_s;
            }

            // We find a window that contains all the required characters
            // and then try to generate smaller windows by adjusting l pointer.
            while (count_s == count_t) {
                int size = r - l + 1;
                if (size < min) {
                    min = size;
                    pivot = l;
                }

                ch = source[l];
                if (bag_t[ch] > 0) {
                    --bag_s[ch];
                    if (bag_s[ch] == bag_t[ch] - 1) {
                        --count_s;
                    }
                }

                ++l;
            }

            ++r;
        }

        return (min < INT_MAX) ? source.substr(pivot, min) : "";
    }
};
class Solution {
public:
    /**
     * @param pages: an array of integers
     * @param k: An integer
     * @return: an integer
     */
    int copyBooks(vector<int> &books, int k) {
        // write your code here

        /**
         *  n piles of books, k copiers
         *
         *  T =   MAX (Bi)
         *      1<=i<=n
         *
         *  B1, B2, ..., Bn
         *
         *  O(nk)
         *
         *  3, 2, 4
         *
         *  l = 1, r = 9
         *  m = (l + r) / 2 = 2
         *
         *  O(nlogk)
         */

        if (books.empty() || k == 0) {
            return 0;
        }

        int l = 1, r = 0;
        for (int book : books) {
            r += book;
        }

        while (l + 1 < r) {
            int m = l + (r - l) / 2;

            if (!canHandle(books, m, k)) {
                l = m;
            } else {
                r = m;
            }
        }

        return canHandle(books, l, k) ? l : r;
    }

private:
    bool canHandle(const std::vector<int>& books, int period, int k) {

        int sum = 1;
        int left = period;

        for (int book : books) {
            if (book > period) {
                return false;
            }

            left -= book;
            if (left < 0) {
                ++sum;
                left = period - book;
            }
        }

        return sum <= k;
    }
};
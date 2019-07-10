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
         *  Given N books, K copiers, and the total number of pages is S. We
         *  need to find the shortest time period for the slowest copier to
         *  finish his work.
         *
         *  Let the candidate period be T, we can gradually increase T from 1
         *  to S to check whether all the copiers can finish their works with
         *  this time period. Hence, we get an O(NS) algorithm. However, we
         *  still can boost the performance by estimating the ideal T with
         *  binary approximation, thus acquiring a O(NlogS) solution.
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
class Solution {
public:
    /**
     * @param n: An integer
     * @param times: an array of integers
     * @return: an integer
     */
    int copyBooksII(int n, vector<int> &times) {
        // write your code here

        /**
         *  Given N books, K copiers, and the total number of pages is S. We
         *  need to find the shortest time period for the copiers to finish
         *  the job.
         *
         *  Let the candidate period be T, we can gradually increase T from 1
         *  to S to check whether all the copiers can finish their tasks with
         *  this time period. Hence, we get an O(NS) algorithm. However, we
         *  still can boost the performance by estimating the ideal T with
         *  binary approximation, thus acquiring a O(NlogS) solution.
         */

        if (times.empty() || n == 0) {
            return 0;
        }

        int l = 1;
        int r = 0;
        for (int time :times) {
            r = std::max(r, time);
        }
        r *= n;

        while (l + 1 < r) {
            int m = l + (r - l) / 2;

            if (canHandle(times, m, n)) {
                r = m;
            } else {
                l = m;
            }
        }

        return canHandle(times, l, n) ? l : r;
    }

private:
    bool canHandle(const auto& times, int estimation, int n) {

        int sum = 0;
        for (int time : times) {
            sum += estimation / time;
        }

        return sum >= n;
    }
};
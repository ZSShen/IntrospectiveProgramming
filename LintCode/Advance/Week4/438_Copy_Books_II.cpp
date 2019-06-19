class Solution {
public:
    /**
     * @param n: An integer
     * @param times: an array of integers
     * @return: an integer
     */
    int copyBooksII(int n, vector<int> &times) {
        // write your code here

        if (times.empty() || n == 0) {
            return 0;
        }

        int l = 1, max = 0;
        for (int time : times) {
            max = std::max(max, time);
        }
        int r = max * n;

        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (countBooks(times, m) >= n) {
                r = m;
            } else {
                l = m;
            }
        }

        return countBooks(times, l) == n ? l : r;
    }

private:
    int countBooks(std::vector<int>& times, int ts) {

        int sum = 0;
        for (int time : times) {
            sum += ts / time;
        }
        return sum;
    }
};

// The DP solution
class Solution {
public:
    /**
     * @param n: a positive integer
     * @param primes: the given prime list
     * @return: the nth super ugly number
     */
    int nthSuperUglyNumber(int n, vector<int> &primes) {
        // write your code here

        int size = primes.size();
        std::vector<int> pointers(size, 0);

        std::vector<long long> dp;
        dp.push_back(1);

        for (int i = 2 ; i <= n ; ++i) {

            std::vector<long long> cands;
            long long opt = std::numeric_limits<long long>::max();

            for (int j = 0 ; j < size ; ++j) {
                long long cand = dp[pointers[j]] * primes[j];
                cands.push_back(cand);
                opt = std::min(opt, cand);
            }

            for (int j = 0 ; j < size ; ++j) {
                if (opt == cands[j]) {
                    ++pointers[j];
                }
            }

            dp.push_back(opt);
        }

        return static_cast<int>(dp[n - 1]);
    }
};


class Solution {
public:
    /**
     * @param n: a positive integer
     * @param primes: the given prime list
     * @return: the nth super ugly number
     */
    int nthSuperUglyNumber(int n, vector<int> &primes) {
        // write your code here

        std::set<long, std::less<long>> queue;
        queue.insert(1);

        long nth = 0;
        for (int i = 0 ; i < n ; ++i) {
            nth = *queue.begin();
            queue.erase(nth);

            for (int prime : primes) {
                queue.insert(nth * prime);
            }
        }

        return nth;
    }
};

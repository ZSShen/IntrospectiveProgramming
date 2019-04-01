
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

// The solution based on priority queue
class Solution {
public:
    /**
     * @param n: a positive integer
     * @param primes: the given prime list
     * @return: the nth super ugly number
     */
    int nthSuperUglyNumber(int n, vector<int> &primes) {
        // write your code here

        std::priority_queue<
            long long, std::vector<long long>, std::greater<long long>> queue;
        std::unordered_set<long long> set;

        queue.push(1);
        long long nth;
        for (int i = 1 ; i <= n ; ++i) {
            nth = queue.top();
            queue.pop();

            for (int prime : primes) {
                long long num = nth * prime;
                if (set.count(num) == 1) {
                    continue;
                }
                set.insert(num);
                queue.push(num);
            }
        }

        return static_cast<int>(nth);
    }
};
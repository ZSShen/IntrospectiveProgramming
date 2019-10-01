class Solution {
public:
    /**
     * @param n: a integer
     * @return: return a integer
     */
    int countPrimes(int n) {
        // write your code here

        std::vector<bool> is_prime(n + 1, true);
        int count = 0;

        for (int i = 2 ; i < n ; ++i) {
            if (is_prime[i]) {
                ++count;
                for (int j = 2 ; i * j < n ; ++j) {
                    is_prime[i * j] = false;
                }
            }
        }

        return count;
    }
};
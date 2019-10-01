class Solution {
public:
    /**
     * @param n: a integer, denote the number of teams
     * @return: a string
     */
    string findContestMatch(int n) {
        // write your code here

        int level = std::log2(n);

        std::vector<std::string> pool;
        for (int i = 1 ; i <= n ; ++i) {
            pool.push_back(std::to_string(i));
        }

        for (int i = 0 ; i < level ; ++i) {
            int n = pool.size();

            std::vector<std::string> temp;

            int l = 0, r = n - 1;
            while (l < r) {
                temp.push_back("(" + pool[l] + "," + pool[r] + ")");
                ++l;
                --r;
            }

            pool = std::move(temp);
        }

        return pool[0];
    }
};
class Solution {
public:
    /**
     * @param deadends: the list of deadends
     * @param target: the value of the wheels that will unlock the lock
     * @return: the minimum total number of turns
     */
    int openLock(vector<string> &deadends, string &target) {
        // Write your code here

        /**
         *  0000
         *
         *  1000 0100 0010 0001
         *  9000 0900 0090 0009
         */

        std::unordered_set<std::string> deadlocks;
        for (auto&& word : deadends) {
            deadlocks.emplace(std::move(word));
        }

        if (deadlocks.count(target) == 1|| deadlocks.count("0000") == 1) {
            return -1;
        }

        std::unordered_set<std::string> visit;
        visit.emplace("0000");

        std::queue<std::string> queue;
        queue.push("0000");

        int step = 0;
        while (!queue.empty()) {

            ++step;
            int n = queue.size();
            for (int i = 0 ; i < n ; ++i) {
                auto src = queue.front();
                queue.pop();

                auto dst(src);
                for (int j = 0 ; j < 4 ; ++j) {

                    char back = dst[j];

                    // Move the wheel clock-wise.
                    dst[j] = ((dst[j] - '0' + 1) % 10) + '0';
                    if (dst == target) {
                        return step;
                    }

                    if (deadlocks.count(dst) == 0 && visit.count(dst) == 0) {
                        queue.push(dst);
                        visit.insert(dst);
                    }

                    // Move the whell counter clock-wise.
                    dst[j] = back;
                    dst[j] = ((dst[j] - '0' + 9) % 10) + '0';
                    if (dst == target) {
                        return step;
                    }

                    if (deadlocks.count(dst) == 0 && visit.count(dst) == 0) {
                        queue.push(dst);
                        visit.insert(dst);
                    }

                    dst[j] = back;
                }
            }
        }

        return -1;
    }
};
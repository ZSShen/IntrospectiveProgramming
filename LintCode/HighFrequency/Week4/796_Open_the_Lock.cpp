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
            int size = queue.size();

            for (int i = 0 ; i < size ; ++i) {
                auto src = queue.front();
                queue.pop();

                for (int i = 0 ; i < 4 ; ++i) {

                    // Move the wheel clock-wise.
                    auto dst =
                        src.substr(0, i) +
                        std::to_string((src[i] - '0' + 1) % 10) +
                        src.substr(i + 1, 3 - i);

                    if (dst == target) {
                        return step;
                    }

                    if (deadlocks.count(dst) == 0 && visit.count(dst) == 0) {
                        queue.push(dst);
                        visit.emplace(std::move(dst));
                    }

                    // Move the wheel counter clock-wise.
                    dst =
                        src.substr(0, i) +
                        std::to_string((src[i] - '0' + 9) % 10) +
                        src.substr(i + 1, 3 - i);

                    if (dst == target) {
                        return step;
                    }

                    if (deadlocks.count(dst) == 0 && visit.count(dst) == 0) {
                        queue.push(dst);
                        visit.emplace(std::move(dst));
                    }
                }
            }
        }

        return -1;
    }
};
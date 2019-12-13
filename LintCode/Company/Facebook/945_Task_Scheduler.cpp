class Solution {
public:
    /**
     * @param tasks: the given char array representing tasks CPU need to do
     * @param n: the non-negative cooling interval
     * @return: the least number of intervals the CPU will take to finish all the given tasks
     */
    int leastInterval(string &tasks, int n) {
        // write your code here

        std::unordered_map<char, int> map;
        for (char ch : tasks) {
            ++map[ch];
        }

        std::priority_queue<int, std::vector<int>, std::less<int>> queue;
        for (const auto& pair : map) {
            queue.push(pair.second);
        }

        int sum = 0;

        while (!queue.empty()) {

            // Generate a task bundle.
            std::vector<int> temp;
            for (int i = 0 ; i < n + 1 ; ++i) {
                if (!queue.empty()) {
                    temp.push_back(queue.top());
                    queue.pop();
                }
            }

            for (int freq : temp) {
                if (--freq > 0) {
                    queue.push(freq);
                }
            }

            // Accumulate the total time units.
            sum += (!queue.empty()) ? (n + 1) : temp.size();
        }

        return sum;
    }
};
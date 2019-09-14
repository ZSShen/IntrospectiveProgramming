class Solution {
public:
    /**
     * @param t: the time of each employee to pass a meeage
     * @param subordinate: the subordinate of each employee
     * @return: the time of the last staff recieve the message
     */
    int deliverMessage(vector<int> &t, vector<vector<int>> &subordinate) {
        // Write your code here

        int size = t.size();
        std::vector<int> time(size, 0);

        std::queue<int> queue;
        queue.push(0);

        while (!queue.empty()) {

            int n = queue.size();
            for (int i = 0 ; i < n ; ++i) {
                auto src = queue.front();
                queue.pop();

                for (int dst : subordinate[src]) {
                    if (dst == -1) {
                        continue;
                    }
                    time[dst] = time[src] + t[src];
                    queue.push(dst);
                }
            }
        }

        int max = -1;
        for (int num : time) {
            max = std::max(max, num);
        }
        return max;
    }
};
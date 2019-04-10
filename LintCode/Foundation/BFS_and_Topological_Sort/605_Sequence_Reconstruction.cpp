class Solution {
public:
    /**
     * @param org: a permutation of the integers from 1 to n
     * @param seqs: a list of sequences
     * @return: true if it can be reconstructed only one or false
     */
    bool sequenceReconstruction(vector<int> &org, vector<vector<int>> &seqs) {
        // write your code here

        std::unordered_map<int, std::vector<int>> list;
        for (int src : org) {
            list[src] = std::vector<int>();
        }

        int count = 0;
        std::unordered_map<int, int> indeg;
        for (const auto& seq : seqs) {
            int len = seq.size();
            count += len;
            for (int i = 0 ; i < len - 1 ; ++i) {
                int src = seq[i];
                int dst = seq[i + 1];
                list[src].push_back(dst);
                ++indeg[dst];
            }
        }

        if (count < list.size()) {
            return false;
        }

        std::queue<int> queue;
        count = 0;

        for (const auto& pair : list) {
            int src = pair.first;
            if (indeg.count(src) == 0) {
                queue.push(src);
                ++count;
                if (count == 2) {
                    return false;
                }
            }
        }

        std::vector<int> order;

        while (!queue.empty()) {
            int src = queue.front();
            queue.pop();

            order.push_back(src);
            count = 0;

            for (int dst : list[src]) {
                --indeg[dst];
                if (indeg[dst] == 0) {
                    queue.push(dst);
                    ++count;
                    if (count == 2) {
                        return false;
                    }
                }
            }
        }

        return order == org;
    }
};
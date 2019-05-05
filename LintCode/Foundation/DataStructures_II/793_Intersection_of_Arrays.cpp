class Solution {
public:
    /**
     * @param arrs: the arrays
     * @return: the number of the intersection of the arrays
     */
    int intersectionOfArrays(vector<vector<int>> &arrs) {
        // write your code here

        int size = arrs.size();
        if (size == 0) {
            return 0;
        }

        for (auto& arr : arrs) {
            std::sort(arr.begin(), arr.end());
        }

        std::vector<int> inter(arrs[0]);
        for (int i = 1 ; i < size ; ++i) {
            std::vector<int> temp;

            int j = 0, k = 0;
            const auto& arr = arrs[i];
            int bnd_j = inter.size(), bnd_k = arr.size();

            while (j < bnd_j && k < bnd_k) {
                if (inter[j] == arr[k]) {
                    temp.push_back(inter[j]);
                    ++j;
                    ++k;
                    continue;
                }

                if (inter[j] > arr[k]) {
                    ++k;
                } else {
                    ++j;
                }
            }

            inter = std::move(temp);
        }

        return inter.size();
    }
};


class Solution {
public:
    /**
     * @param arrs: the arrays
     * @return: the number of the intersection of the arrays
     */
    int intersectionOfArrays(vector<vector<int>> &arrs) {
        // write your code here

        int size = arrs.size();
        if (size == 0) {
            return 0;
        }

        std::unordered_map<int, int> map;

        for (int i = 0 ; i < size ; ++i) {
            for (int num : arrs[i]) {
                ++map[num];
            }
        }

        int ans = 0;
        for (const auto& pair : map) {
            if (pair.second == size) {
                ++ans;
            }
        }

        return ans;
    }
};


struct Record {
    int num;
    int r;
    int c;

    Record(int num, int r, int c)
      : num(num), r(r), c(c)
    { }
};


struct RecordCompare {

    bool operator() (const Record& lhs, const Record& rhs) {
        return lhs.num > rhs.num;
    }
};


class Solution {
public:
    /**
     * @param arrs: the arrays
     * @return: the number of the intersection of the arrays
     */
    int intersectionOfArrays(vector<vector<int>> &arrs) {
        // write your code here

        int size = arrs.size();
        if (size == 0) {
            return 0;
        }

        std::priority_queue<Record, std::vector<Record>, RecordCompare> queue;

        for (int i = 0 ; i < size ; ++i) {
            if (arrs[i].size() == 0) {
                return 0;
            }
            std::sort(arrs[i].begin(), arrs[i].end());
            queue.push(Record(arrs[i][0], i, 0));
        }

        int ans = 0;
        int freq = 0;
        int last = 0;
        while (!queue.empty()) {
            auto top = queue.top();
            queue.pop();

            int num = top.num;
            int r = top.r;
            int c = top.c;

            // Compensate the queue.
            if (c + 1 < arrs[r].size()) {
                queue.push(Record(arrs[r][c + 1], r, c + 1));
            }

            if (freq == 0) {
                last = num;
                freq = 1;
                continue;
            }

            if (num == last) {
                ++freq;
                if (freq == size) {
                    ++ans;
                }
                continue;
            }

            last = num;
            freq = 1;
        }

        return ans;
    }
};

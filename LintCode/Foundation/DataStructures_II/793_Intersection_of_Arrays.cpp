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




struct Record {
    int num;
    int id;
    int index;

    Record(int num, int id, int index)
      : num(num), id(id), index(index)
    { }
};


struct RecordCompare {
    bool operator() (const auto& lhs, const auto& rhs) {
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

        std::priority_queue<Record, std::vector<Record>, RecordCompare> queue;

        int k = arrs.size();
        for (int i = 0 ; i < k ; ++i) {
            if (!arrs[i].empty()) {
                std::sort(arrs[i].begin(), arrs[i].end());
                queue.push(Record(arrs[i][0], i, 0));
            }
        }

        // If all vectors are empty.
        if (queue.empty()) {
            return 0;
        }

        auto rec = queue.top();
        queue.pop();

        int prev = rec.num;
        int count = 1;
        int id = rec.id;
        int index = rec.index;

        if (index < arrs[id].size() - 1) {
            queue.push(Record(arrs[id][index + 1], id, index + 1));
        }

        int ans = 0;

        while (!queue.empty()) {
            rec = queue.top();
            queue.pop();

            int curr = rec.num;
            id = rec.id;
            index = rec.index;

            if (index < arrs[id].size() - 1) {
                queue.push(Record(arrs[id][index + 1], id, index + 1));
            }

            if (curr == prev) {
                ++count;
            }

            if (curr != prev) {
                if (count >= k) {
                    ++ans;
                }
                count = 1;
                prev = curr;
            }
        }

        if (count >= k) {
            ++ans;
        }

        return ans;
    }
};

struct Record {
    int num;
    int r;
    int c;

    Record(int num, int r, int c)
      : num(num),
        r(r),
        c(c)
    { }
};


struct RecordCompare {

    bool operator() (const Record& lhs, const Record& rhs) {
        return lhs.num < rhs.num;
    }
};


class Solution {
public:
    /**
     * @param arrays: a list of array
     * @param k: An integer
     * @return: an integer, K-th largest element in N arrays
     */
    int KthInArrays(vector<vector<int>> &arrays, int k) {
        // write your code here

        /**
         * S: The average length of the input arrays.
         * O(N*SlogS + K*logN)
         */

        std::priority_queue<Record, std::vector<Record>, RecordCompare> queue;

        int size = arrays.size();

        for (int i = 0 ; i < size ; ++i) {
            auto& array = arrays[i];
            if (array.empty()) {
                continue;
            }

            std::sort(array.begin(), array.end(), std::greater<int>());
            queue.push(Record(array[0], i, 0));
        }

        int kth;
        for (int i = 0 ; i < k ; ++i) {
            auto top = queue.top();
            queue.pop();

            kth = top.num;
            int r = top.r;
            int c = top.c;

            if (c + 1 < arrays[r].size()) {
                queue.push(Record(arrays[r][c + 1], r, c + 1));
            }
        }

        return kth;
    }
};


class Solution {
public:
    /**
     * @param arrays: a list of array
     * @param k: An integer
     * @return: an integer, K-th largest element in N arrays
     */
    int KthInArrays(vector<vector<int>> &arrays, int k) {
        // write your code here

        std::priority_queue<int, std::vector<int>, std::greater<int>> queue;
        for (const auto& array : arrays) {
            for (int num : array) {
                queue.push(num);

                if (queue.size() > k) {
                    queue.pop();
                }
            }
        }

        return queue.top();
    }
};
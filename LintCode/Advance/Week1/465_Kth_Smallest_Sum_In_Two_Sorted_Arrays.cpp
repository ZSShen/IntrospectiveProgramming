

struct Record {
    int sum;
    int a_idx;
    int b_idx;

    Record(int sum, int a_idx, int b_idx)
      : sum(sum),
        a_idx(a_idx),
        b_idx(b_idx)
    { }
};


struct RecordCompare {

    bool operator() (const Record& lhs, const Record& rhs) {
        return lhs.sum > rhs.sum;
    }
};


class Solution {
public:
    /**
     * @param A: an integer arrays sorted in ascending order
     * @param B: an integer arrays sorted in ascending order
     * @param k: An integer
     * @return: An integer
     */
    int kthSmallestSum(vector<int> &A, vector<int> &B, int k) {
        // write your code here

        /**
         *  a = [1, 7, 11]
         *  b = [2, 4, 6]
         *
         *
         *  3, 5, 7, 9
         *
         *  (1, 2) -> (1, 4) -> (1, 6) -> (6, 7) -> (2, 11)
         *            (2, 7)    (4, 7)              (7, 4)
         *
         *  O(KlogK)
         */

        int size_a = A.size();
        int size_b = B.size();

        std::priority_queue<Record, std::vector<Record>, RecordCompare> queue;
        queue.push(Record(A[0] + B[0], 0, 0));

        std::vector<std::vector<bool>>
            visit(size_a, std::vector<bool>(size_b, false));
        visit[0][0] = true;

        int kth;
        for (int i = 0 ; i < k ; ++i) {
            auto top = queue.top();
            queue.pop();

            kth = top.sum;
            int a_idx = top.a_idx;
            int b_idx = top.b_idx;

            if (b_idx + 1 < size_b) {
                int new_b_idx = b_idx + 1;

                if (!visit[a_idx][new_b_idx]) {
                    queue.push(
                        Record(A[a_idx] + B[new_b_idx], a_idx, new_b_idx));
                    visit[a_idx][new_b_idx] = true;
                }
            }

            if (a_idx + 1 < size_a) {
                int new_a_idx = a_idx + 1;

                if (!visit[new_a_idx][b_idx]) {
                    queue.push(
                        Record(A[new_a_idx] + B[b_idx], new_a_idx, b_idx));
                    visit[new_a_idx][b_idx] = true;
                }
            }
        }

        return kth;
    }
};
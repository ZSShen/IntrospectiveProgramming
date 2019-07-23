
struct Record {
    int sum;
    int idx_a;
    int idx_b;

    Record(int sum, int idx_a, int idx_b)
      : sum(sum), idx_a(idx_a), idx_b(idx_b)
    { }
};


struct RecordCompare {

    bool operator() (const auto& lhs, const auto& rhs) {
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

        for (int i = 0 ; i < k - 1 ; ++i) {
            auto rec = queue.top();
            queue.pop();

            int idx_a = rec.idx_a;
            int idx_b = rec.idx_b;
            int idx_na = idx_a + 1;
            int idx_nb = idx_b + 1;

            if (idx_na < size_a && !visit[idx_na][idx_b]) {
                queue.push(Record(A[idx_na] + B[idx_b], idx_na, idx_b));
                visit[idx_na][idx_b] = true;
            }

            if (idx_nb < size_b && !visit[idx_a][idx_nb]) {
                queue.push(Record(A[idx_a] + B[idx_nb], idx_a, idx_nb));
                visit[idx_a][idx_nb] = true;
            }
        }

        auto rec = queue.top();
        return rec.sum;
    }
};
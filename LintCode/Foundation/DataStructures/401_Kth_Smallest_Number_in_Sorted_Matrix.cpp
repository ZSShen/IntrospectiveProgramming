

struct Record {
    int num;
    int r, c;

    Record(int num, int r, int c)
      : num(num), r(r), c(c)
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
     * @param matrix: a matrix of integers
     * @param k: An integer
     * @return: the kth smallest number in the matrix
     */
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        // write your code here

        int num_r = matrix.size();
        if (num_r == 0) {
            return 0;
        }

        int num_c = matrix[0].size();
        if (num_c == 0) {
            return 0;
        }

        if (k == 0) {
            return 0;
        }

        std::priority_queue<Record, std::vector<Record>, RecordCompare> queue;
        queue.push(Record(matrix[0][0], 0, 0));

        std::vector<std::vector<bool>>
            visit(num_r, std::vector<bool>(num_c, false));
        visit[0][0] = true;

        for (int i = 0 ; i < k - 1; ++i) {
            auto rec = queue.top();
            queue.pop();

            int r = rec.r;
            int c = rec.c;
            int nr = r + 1;
            int nc = c + 1;

            if (nr < num_r && !visit[nr][c]) {
                queue.push(Record(matrix[nr][c], nr, c));
                visit[nr][c] = true;
            }
            if (nc < num_c && !visit[r][nc]) {
                queue.push(Record(matrix[r][nc], r, nc));
                visit[r][nc] = true;
            }
        }

        auto rec = queue.top();
        return rec.num;
    }
};

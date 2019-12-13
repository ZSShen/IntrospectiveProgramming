
struct Record {
    int value;
    int x, y;

    Record(int value, int x, int y)
      : value(value), x(x), y(y)
    { }
};


struct RecordCompare {
    bool operator() (const auto& lhs, const auto& rhs) {
        return lhs.value < rhs.value;
    }
};


class Solution {
public:
    Solution()
      : directs({{1, 0}, {-1, 0}, {0, 1}, {0, -1}})
    { }

    /**
     * @param A: a List[List[int]]
     * @return: Return the maximum score of a path
     */
    int maximumMinimumPath(vector<vector<int>> &A) {
        // Write your code here

        /**
         *  3 3 1 1
         *  2 1 1 1
         *  2 2 2 2
         */

        int m = A.size();
        int n = A[0].size();

        std::vector<std::vector<bool>> visit(m, std::vector<bool>(n, false));
        visit[0][0] = true;

        std::priority_queue<Record, std::vector<Record>, RecordCompare> queue;
        queue.push(Record(A[0][0], 0, 0));

        int ans = A[0][0];

        while (!queue.empty()) {
            auto rec = queue.top();
            queue.pop();

            int x = rec.x;
            int y = rec.y;
            int value = rec.value;

            ans = std::min(ans, value);
            if (x == m - 1 && y == n - 1) {
                break;
            }

            for (const auto& direct : directs) {
                int nx = x + direct[0];
                int ny = y + direct[1];

                if (!(nx >= 0 && ny >= 0 && nx < m && ny < n) ||
                    visit[nx][ny]) {
                    continue;
                }

                queue.push(Record(A[nx][ny], nx, ny));
                visit[nx][ny] = true;
            }
        }

        return ans;
    }

private:
    std::vector<std::vector<int>> directs;
};

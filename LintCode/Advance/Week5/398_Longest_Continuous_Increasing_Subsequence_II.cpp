
struct Record {
    int x;
    int y;
    int val;

    Record(int x, int y, int val)
      : x(x), y(y), val(val)
    { }
};


struct RecordCompare {
    bool operator() (const Record& lhs, const Record& rhs) {
        return lhs.val > rhs.val;
    }
};


class Solution {
public:
    Solution()
      : directs({{1, 0}, {-1, 0}, {0, 1}, {0, -1}})
    { }

    /**
     * @param matrix: A 2D-array of integers
     * @return: an integer
     */
    int longestContinuousIncreasingSubsequence2(vector<vector<int>> &matrix) {
        // write your code here

        int num_r = matrix.size();
        if (num_r == 0) {
            return 0;
        }

        int num_c = matrix[0].size();
        if (num_c == 0) {
            return 0;
        }

        int ans = 1;

        std::vector<std::vector<int>> dp(num_r, std::vector<int>(num_c, 1));
        std::priority_queue<Record, std::vector<Record>, RecordCompare> queue;
        for (int i = 0 ; i < num_r ; ++i) {
            for (int j = 0 ; j < num_c ; ++j) {
                queue.push(Record(i, j, matrix[i][j]));
            }
        }

        while (!queue.empty()) {
            auto top = queue.top();
            queue.pop();

            int x = top.x;
            int y = top.y;
            int val = top.val;

            for (const auto& direct : directs) {
                int nx = x + direct[0];
                int ny = y + direct[1];

                if (!(nx >= 0 && ny >= 0 && nx < num_r && ny < num_c)) {
                    continue;
                }

                if (matrix[nx][ny] > val) {
                    dp[nx][ny] = std::max(dp[nx][ny], dp[x][y] + 1);
                    ans = std::max(ans, dp[nx][ny]);
                }
            }
        }

        return ans;
    }

private:
    std::vector<std::vector<int>> directs;
};


struct Record {
    int x;
    int y;
    int h;

    Record(int x, int y, int h)
      : x(x), y(y), h(h)
    { }
};


struct RecordCompare {
    bool operator() (const Record& lhs, const Record& rhs) {
        return lhs.h > rhs.h;
    }
};


class Solution {
public:
    Solution()
      : directs({{1, 0}, {-1, 0}, {0, 1}, {0, -1}})
    { }

    /**
     * @param heights: a matrix of integers
     * @return: an integer
     */
    int trapRainWater(vector<vector<int>> &heights) {
        // write your code here

        int num_r = heights.size();
        if (num_r == 0) {
            return 0;
        }

        int num_c = heights[0].size();
        if (num_c == 0) {
            return 0;
        }

        std::priority_queue<Record, std::vector<Record>, RecordCompare> queue;
        std::vector<std::vector<bool>>
            visit(num_r, std::vector<bool>(num_c, false));

        for (int i = 0 ; i < num_r ; ++i) {
            for (int j = 0 ; j < num_c ; ++j) {
                if (i == 0 || j == 0 || i == num_r - 1 || j == num_c - 1) {
                    queue.push(Record(i, j, heights[i][j]));
                    visit[i][j] = true;
                }
            }
        }

        int ans = 0;
        int level = 0;
        while (!queue.empty()) {
            auto top = queue.top();
            queue.pop();

            level = std::max(level, top.h);
            int x = top.x;
            int y = top.y;

            for (const auto& direct : directs) {
                int nx = x + direct[0];
                int ny = y + direct[1];

                if (!(nx >= 0 && ny >= 0 && nx < num_r && ny < num_c) ||
                    visit[nx][ny]) {
                    continue;
                }

                queue.push(Record(nx, ny, heights[nx][ny]));
                visit[nx][ny] = true;

                if (heights[nx][ny] < level) {
                    ans += level - heights[nx][ny];
                }
            }
        }

        return ans;
    }

private:
    std::vector<std::vector<int>> directs;
};

struct Record {
    int r, c;

    Record(int r, int c)
      : r(r), c(c)
    { }
};


class Solution {
public:
    Solution()
      : directs({{1, 0}, {-1, 0}, {0, 1}, {0, -1}})
    { }

    /**
     * @param rooms: m x n 2D grid
     * @return: nothing
     */
    void wallsAndGates(vector<vector<int>> &rooms) {
        // write your code here

        int num_r = rooms.size();
        if (num_r == 0) {
            return;
        }

        int num_c = rooms[0].size();
        if (num_c == 0) {
            return;
        }

        std::vector<std::vector<bool>>
            visit(num_r, std::vector<bool>(num_c, false));
        std::queue<Record> queue;

        for (int r = 0 ; r < num_r ; ++r) {
            for (int c = 0 ; c < num_c ; ++c) {
                if (rooms[r][c] != 0) {
                    continue;
                }
                visit[r][c] = true;
                queue.push(Record(r, c));
            }
        }

        int level = 0;

        while (!queue.empty()) {
            ++level;
            int n = queue.size();

            for (int i = 0 ; i < n ; ++i) {
                auto rec = queue.front();
                queue.pop();

                int r = rec.r;
                int c = rec.c;

                for (const auto& direct : directs) {
                    int nr = r + direct[0];
                    int nc = c + direct[1];

                    if (!(nr >= 0 && nc >= 0 && nr < num_r && nc < num_c) ||
                        visit[nr][nc] ||
                        rooms[nr][nc] == -1 ||
                        rooms[nr][nc] == 0) {
                        continue;
                    }

                    if (rooms[nr][nc] == INT_MAX) {
                        rooms[nr][nc] = level;
                    } else {
                        rooms[nr][nc] = std::min(rooms[nr][nc], level);
                    }

                    visit[nr][nc] = true;
                    queue.push(Record(nr, nc));
                }
            }
        }
    }

private:
    std::vector<std::vector<int>> directs;
};
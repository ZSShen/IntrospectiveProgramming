

struct Record {
    int x;
    int y;
    int dist;

    Record(int x, int y, int dist)
      : x(x),
        y(y),
        dist(dist)
    { }
};


class Solution {
public:
    Solution()
      : directs({
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
      }),
        INF(std::numeric_limits<int>::max())
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

        std::queue<Record> queue;
        std::vector<std::vector<bool>>
            visit(num_r, std::vector<bool>(num_c, false));

        for (int x = 0 ; x < num_r ; ++x) {
            for (int y = 0 ; y < num_c ; ++y) {
                if (rooms[x][y] == 0) {
                    queue.push(Record(x, y, 0));
                    visit[x][y] = true;
                }
            }
        }

        while (!queue.empty()) {
            int size = queue.size();

            for (int i = 0 ; i < size ; ++i) {
                auto front = queue.front();
                queue.pop();

                int x = front.x;
                int y = front.y;
                int dist = front.dist;

                for (const auto& direct : directs) {
                    int nx = x + direct[0];
                    int ny = y + direct[1];

                    if (!(nx >= 0 && nx < num_r && ny >= 0 && ny < num_c) ||
                        visit[nx][ny] ||
                        (rooms[nx][ny] == -1 || rooms[nx][ny] == 0)) {
                        continue;
                    }

                    visit[nx][ny] = true;
                    rooms[nx][ny] = dist + 1;
                    queue.push(Record(nx, ny, dist + 1));
                }
            }
        }
    }


private:
    std::vector<std::vector<int>> directs;
    const int INF;
};
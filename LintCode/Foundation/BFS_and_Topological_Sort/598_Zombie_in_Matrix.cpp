class Solution {
public:
    /**
     * @param grid: a 2D integer grid
     * @return: an integer
     */
    int zombie(vector<vector<int>> &grid) {
        // write your code here

        int num_r = grid.size();
        if (num_r == 0) {
            return -1;
        }
        int num_c = grid[0].size();
        if (num_c == 0) {
            return -1;
        }

        int count_people = 0;
        bool visit[num_r][num_c] = {{false}};
        std::queue<std::pair<int, int>> queue;
        for (int i = 0 ; i < num_r ; ++i) {
            for (int j = 0 ; j < num_c ; ++j) {
                if (grid[i][j] == 0) {
                    ++count_people;
                }
                if (grid[i][j] == 1) {
                    visit[i][j] = true;
                    queue.push(std::make_pair(i, j));
                }
            }
        }

        int count_day = 0;
        while (!queue.empty()) {

            int size = queue.size();
            for (int i = 0 ; i < size ; ++i) {
                auto loc = queue.front();
                queue.pop();

                int r = loc.first, c = loc.second;

                if (r > 0 && !visit[r - 1][c] && grid[r - 1][c] == 0) {
                    --count_people;
                    visit[r - 1][c] = true;
                    queue.push(std::make_pair(r - 1, c));
                }
                if (r < num_r - 1 && !visit[r + 1][c] && grid[r + 1][c] == 0) {
                    --count_people;
                    visit[r + 1][c] = true;
                    queue.push(std::make_pair(r + 1, c));
                }
                if (c > 0 && !visit[r][c - 1] && grid[r][c - 1] == 0) {
                    --count_people;
                    visit[r][c - 1] = true;
                    queue.push(std::make_pair(r, c - 1));
                }
                if (c < num_c - 1 && !visit[r][c + 1] && grid[r][c + 1] == 0) {
                    --count_people;
                    visit[r][c + 1] = true;
                    queue.push(std::make_pair(r, c + 1));
                }
            }

            ++count_day;
        }

        --count_day;
        return count_people == 0 ? count_day : -1;
    }
};



struct Record {
    int x;
    int y;

    Record(int x, int y)
      : x(x),
        y(y)
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
      })
    { }

    /**
     * @param grid: a 2D integer grid
     * @return: an integer
     */
    int zombie(vector<vector<int>> &grid) {
        // write your code here

        int num_r = grid.size();
        if (num_r == 0) {
            return -1;
        }

        int num_c = grid[0].size();
        if (num_c == 0) {
            return -1;
        }

        std::queue<Record> queue;

        for (int x = 0 ; x < num_r ; ++x) {
            for (int y = 0 ; y < num_c ; ++y) {
                if (grid[x][y] == 1) {
                    queue.push(Record(x, y));
                }
            }
        }

        int days = 0;
        while (true) {
            int size = queue.size();

            for (int i = 0 ; i < size ; ++i) {
                auto front = queue.front();
                queue.pop();

                int x = front.x;
                int y = front.y;

                for (const auto& direct : directs) {
                    int nx = x + direct[0];
                    int ny = y + direct[1];

                    if (!(nx >= 0 && nx < num_r && ny >= 0 && ny < num_c) ||
                        (grid[nx][ny] == 2 || grid[nx][ny] == 1)) {
                        continue;
                    }

                    grid[nx][ny] = 1;
                    queue.push(Record(nx, ny));
                }
            }

            if (queue.empty()) {
                break;
            }
            ++days;
        }

        bool check = true;
        for (int x = 0 ; x < num_r ; ++x) {
            for (int y = 0 ; y < num_c ; ++y) {
                if (grid[x][y] == 0) {
                    check = false;
                    break;
                }
            }
        }

        return (check) ? days : -1;
    }

private:
    std::vector<std::vector<int>> directs;
};



struct Record {
    int x, y;

    Record(int x, int y)
      : x(x), y(y)
    { }
};


class Solution {
public:
    Solution()
      : directs({{1, 0}, {-1, 0}, {0, 1}, {0, -1}})
    { }

    /**
     * @param maze: the maze
     * @param start: the start
     * @param destination: the destination
     * @return: whether the ball could stop at the destination
     */
    bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
        // write your code here

        int num_r = maze.size();
        if (num_r == 0) {
            return false;
        }

        int num_c = maze[0].size();
        if (num_c == 0) {
            return false;
        }

        std::vector<std::vector<bool>>
            visit(num_r, std::vector<bool>(num_c, false));
        visit[start[0]][start[1]] = true;

        std::queue<Record> queue;
        queue.push(Record(start[0], start[1]));

        while (!queue.empty()) {

            auto rec = queue.front();
            queue.pop();

            int x = rec.x;
            int y = rec.y;

            for (const auto& direct : directs) {
                int nx = x + direct[0];
                int ny = y + direct[1];

                while ((nx >= 0 && ny >= 0 && nx < num_r && ny < num_c) &&
                        maze[nx][ny] == 0) {
                    nx += direct[0];
                    ny += direct[1];
                }

                nx -= direct[0];
                ny -= direct[1];

                if (nx == destination[0] && ny == destination[1]) {
                    return true;
                }

                if (visit[nx][ny] == false) {
                    queue.push(Record(nx, ny));
                    visit[nx][ny] = true;
                }
            }
        }

        return false;
    }

private:
    std::vector<std::vector<int>> directs;
};
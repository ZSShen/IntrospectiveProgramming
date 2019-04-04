/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

class Solution {
public:
    /**
     * @param grid: a chessboard included 0 (false) and 1 (true)
     * @param source: a point
     * @param destination: a point
     * @return: the shortest path
     */
    int shortestPath(vector<vector<bool>> &grid, Point &source, Point &destination) {
        // write your code here

        int num_r = grid.size();
        if (num_r == 0) {
            return -1;
        }

        int num_c = grid[0].size();
        if (num_c == 0) {
            return -1;
        }

        std::queue<std::pair<Point, int>> queue;
        queue.push(std::make_pair(source, 0));

        grid[source.x][source.y] = true;

        std::vector<std::vector<int>> direct;
        direct.push_back({1, 2});
        direct.push_back({1, -2});
        direct.push_back({-1, 2});
        direct.push_back({-1, -2});
        direct.push_back({2, 1});
        direct.push_back({2, -1});
        direct.push_back({-2, 1});
        direct.push_back({-2, -1});

        while (!queue.empty()) {
            auto pair = queue.front();
            queue.pop();

            int o_x = pair.first.x;
            int o_y = pair.first.y;
            int step = pair.second;

            for (int i = 0 ; i < 8 ; ++i) {
                int n_x = o_x + direct[i][0];
                int n_y = o_y + direct[i][1];

                if (n_x < 0 || n_x >= num_r ||
                    n_y < 0 || n_y >= num_c ||
                    grid[n_x][n_y]) {
                    continue;
                }

                if (n_x == destination.x && n_y == destination.y) {
                    return step + 1;
                }

                queue.push(std::make_pair(Point(n_x, n_y), step + 1));
                grid[n_x][n_y] = true;
            }
        }

        return -1;
    }
};
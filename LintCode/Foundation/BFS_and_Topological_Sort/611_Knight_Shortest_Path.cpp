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
    Solution()
      : directs({
        {1, 2},
        {1, -2},
        {-1, 2},
        {-1, -2},
        {2, 1},
        {2, -1},
        {-2, 1},
        {-2, -1}
      })
    { }

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

        std::queue<Point> queue;
        queue.push(source);

        grid[source.x][source.y] = true;

        int step = 0;

        while (!queue.empty()) {
            ++step;
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
                        grid[nx][ny]) {
                        continue;
                    }

                    if (nx == destination.x && ny == destination.y) {
                        return step;
                    }

                    grid[nx][ny] = true;
                    queue.push(Point(nx, ny));
                }

            }
        }

        return -1;
    }

private:
    std::vector<std::vector<int>> directs;
};
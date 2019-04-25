
struct Coordinate {
    int x;
    int y;
    
    Coordinate(int x, int y)
      : x(x), y(y)
    { }
};


class Solution {
public:
    Solution() {
        trans.push_back({1, 0});
        trans.push_back({-1, 0});
        trans.push_back({0, 1});
        trans.push_back({0, -1});
    }

    /**
     * @param grid: a 2D grid
     * @return: An integer
     */
    int shortestDistance(vector<vector<int>> &grid) {
        // write your code here
        
        int m = grid.size();
        if (m == 0) {
            return -1;
        }
        
        int n = grid[0].size();
        if (n == 0) {
            return -1;
        }

        std::vector<Coordinate> spaces;
        std::vector<Coordinate> houses;
        for (int i = 0 ; i < m ; ++i) {
            for (int j = 0 ; j < n ; ++j) {
                if (grid[i][j] == 0) {
                    spaces.push_back(Coordinate(i, j));
                } else if (grid[i][j] == 1) {
                    houses.push_back(Coordinate(i, j));
                }
            }
        }
        
        std::vector<std::vector<int>> reach(m, std::vector<int>(n, 0));
        std::vector<std::vector<int>> dist(m, std::vector<int>(n, 0));
        
        for (const auto& house : houses) {
            runBFS(house, m, n, grid, reach, dist);
        }
        
        int num_house = houses.size();
        int ans = std::numeric_limits<int>::max();
        for (const auto& space : spaces) {
            if (reach[space.x][space.y] < num_house) {
                continue;
            }
            ans = std::min(ans, dist[space.x][space.y]);
        }
        
        return (ans == std::numeric_limits<int>::max()) ? -1 : ans;
    }

private:
    std::vector<std::vector<int>> trans;

    void runBFS(
            const Coordinate& house,
            int m,
            int n,
            const std::vector<std::vector<int>>& grid,
            std::vector<std::vector<int>>& reach,
            std::vector<std::vector<int>>& dist) {
        
        std::queue<Coordinate> queue;
        queue.push(house);

        std::vector<std::vector<bool>> visit(m, std::vector<bool>(n, false));
        visit[house.x][house.y] = true;

        int sum = 0;
        while (!queue.empty()) {
            ++sum;

            int size = queue.size();
            for (int i = 0 ; i < size ; ++i) {
                auto top = queue.front();
                queue.pop();

                for (const auto& cord : trans) {
                    int x = top.x + cord[0];
                    int y = top.y + cord[1];
                    
                    if (!(x >= 0 && x < m && y >= 0 && y < n) ||
                        visit[x][y]) {
                        continue;
                    }
                    
                    visit[x][y] = true;
                    if (grid[x][y] == 0) {
                        ++reach[x][y];
                        dist[x][y] += sum;
                        queue.push(Coordinate(x, y));
                    }
                }
            }
        }
    }
    
};
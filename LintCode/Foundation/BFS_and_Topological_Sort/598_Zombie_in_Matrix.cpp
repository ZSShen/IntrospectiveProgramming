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
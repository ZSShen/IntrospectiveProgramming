class Solution {
public:
    /**
     * @param image: a binary matrix with '0' and '1'
     * @param x: the location of one of the black pixels
     * @param y: the location of one of the black pixels
     * @return: an integer
     */
    int minArea(vector<vector<char>> &image, int x, int y) {
        // write your code here

        int num_row = image.size();
        if (num_row == 0) {
            return 0;
        }

        int num_col = image[0].size();
        if (num_col == 0) {
            return 0;
        }

        std::vector<std::vector<bool>>
            visit(num_row, std::vector<bool>(num_col, false));
        visit[x][y] = true;

        std::queue<std::pair<int, int>> queue;
        queue.push(std::make_pair(x, y));

        int min_row = INT_MAX;
        int min_col = INT_MAX;
        int max_row = INT_MIN;
        int max_col = INT_MIN;

        while (!queue.empty()) {
            auto pair = queue.front();
            int r = pair.first;
            int c = pair.second;
            queue.pop();

            min_row = std::min(min_row, r);
            min_col = std::min(min_col, c);
            max_row = std::max(max_row, r);
            max_col = std::max(max_col, c);

            if (r >= 1 && !visit[r - 1][c] && image[r - 1][c] == '1') {
                visit[r - 1][c] = true;
                queue.push(std::make_pair(r - 1, c));
            }
            if (r < num_row - 1 && !visit[r + 1][c] && image[r + 1][c] == '1') {
                visit[r + 1][c] = true;
                queue.push(std::make_pair(r + 1, c));
            }

            if (c >= 1 && !visit[r][c - 1] && image[r][c - 1] == '1') {
                visit[r][c - 1] = true;
                queue.push(std::make_pair(r, c - 1));
            }
            if (c < num_col - 1 && !visit[r][c + 1] && image[r][c + 1] == '1') {
                visit[r][c + 1] = true;
                queue.push(std::make_pair(r, c + 1));
            }
        }

        return (max_row - min_row + 1) * (max_col - min_col + 1);
    }
};
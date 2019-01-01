class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {

        int num_row = matrix.size();
        int num_col = matrix[0].size();

        std::queue<std::pair<int, int>> queue;
        for (int i = 0 ; i < num_row ; ++i) {
            for (int j = 0 ; j < num_col ; ++j) {
                if (matrix[i][j] == 0) {
                    queue.push(std::make_pair(i, j));
                } else {
                    matrix[i][j] = INT_MAX;
                }
            }
        }

        std::vector<std::pair<int, int>> directions{
            {-1, 0},
            {1, 0},
            {0, -1},
            {0, 1}
        };

        while (!queue.empty()) {
            auto begin = queue.front();
            queue.pop();

            for (const auto& direction : directions) {
                int row = begin.first + direction.first;
                int col = begin.second + direction.second;

                if (row < 0 ||
                    row == num_row ||
                    col < 0 ||
                    col == num_col ||
                    matrix[row][col] <= matrix[begin.first][begin.second]) {
                    continue;
                }

                matrix[row][col] = matrix[begin.first][begin.second] + 1;
                queue.push(std::make_pair(row, col));
            }
        }

        return matrix;
    }
};

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        vector<int> seq;

        if (matrix.size() == 0)
            return seq;

        int num_row = matrix.size();
        int num_col = matrix[0].size();
        bool visit[num_row][num_col];
        memset(visit, false, num_row * num_col);

        int idx_row = 0, idx_col = 0;
        int direct = RIGHT;
        visit[0][0] = true;
        while (true) {
            seq.push_back(matrix[idx_row][idx_col]);

            switch (direct) {
                case RIGHT:
                    if ((idx_col + 1) < num_col &&
                        visit[idx_row][idx_col + 1] == false)
                        ++idx_col;
                    else if ((idx_row + 1) < num_row &&
                             visit[idx_row + 1][idx_col] == false) {
                        ++idx_row;
                        direct = DOWN;
                    } else
                        return seq;
                    break;
                case DOWN:
                    if ((idx_row + 1) < num_row &&
                        visit[idx_row + 1][idx_col] == false)
                        ++idx_row;
                    else if (idx_col > 0 &&
                             visit[idx_row][idx_col - 1] == false) {
                        --idx_col;
                        direct = LEFT;
                    } else
                        return seq;
                    break;
                case LEFT:
                    if (idx_col > 0 &&
                        visit[idx_row][idx_col - 1] == false)
                        --idx_col;
                    else if (idx_row > 0 &&
                             visit[idx_row - 1][idx_col] == false) {
                        --idx_row;
                        direct = UP;
                    } else
                        return seq;
                    break;
                case UP:
                    if (idx_row > 0 &&
                        visit[idx_row - 1][idx_col] == false)
                        --idx_row;
                    else if ((idx_col + 1) < num_col &&
                             visit[idx_row][idx_col + 1] == false) {
                        ++idx_col;
                        direct = RIGHT;
                    } else
                        return seq;
                    break;
            }
            visit[idx_row][idx_col] = true;
        }
    }

private:
    static const int RIGHT = 0;
    static const int DOWN = 1;
    static const int LEFT = 2;
    static const int UP = 3;
};
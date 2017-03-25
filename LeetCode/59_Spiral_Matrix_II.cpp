class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        std::vector<std::vector<int>> mtx(n, std::vector<int>(n, 0));

        if (n == 0) {
            return mtx;            
        }

        int target = n * n;
        int current = 1;
        int row = 0, col = -1;
        char direct = RIGHT;

        while (current <= target) {
            switch (direct) {
            case RIGHT:
                ++col;
                if (col + 1 == n || mtx[row][col + 1] != 0) {
                    direct = DOWN;
                }
                break;

            case DOWN:
                ++row;
                if (row + 1 == n || mtx[row + 1][col] != 0) {
                    direct = LEFT;
                }
                break;

            case LEFT:
                --col;
                if (col - 1 == -1 || mtx[row][col - 1] != 0) {
                    direct = UP;
                }
                break;

            case UP:
                --row;
                if (row - 1 == -1 || mtx[row - 1][col] != 0) {
                    direct = RIGHT;
                }
                break;
            }

            mtx[row][col] = current;
            ++current;
        }

        return mtx;
    }

private:
    enum {
        UP = 0,
        DOWN,
        LEFT,
        RIGHT
    };
};
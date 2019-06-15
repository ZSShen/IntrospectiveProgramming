class Solution {
public:
    Solution()
      : directs({{1, 0}, {-1, 0}, {0, 1}, {0, -1}})
    { }

    bool exist(vector<vector<char>>& board, string word) {

        int num_r = board.size();
        if (num_r == 0) {
            return false;
        }

        int num_c = board[0].size();
        if (num_c == 0) {
            return false;
        }

        int len = word.length();

        for (int i = 0 ; i < num_r ; ++i) {
            for (int j = 0 ; j < num_c ; ++j) {
                if (runBacktracking(board, i, j, num_r, num_c, word, 0, len)) {
                    return true;
                }
            }
        }

        return false;
    }

private:
    bool runBacktracking(
            std::vector<std::vector<char>>& board,
            int r, int c,
            int num_r, int num_c,
            const std::string& word,
            int index,
            int bound) {

        if (board[r][c] != word[index]) {
            return false;
        }

        if (index == bound - 1) {
            return true;
        }

        char ch = 0;
        std::swap(ch, board[r][c]);
        bool res = false;

        for (const auto& direct : directs) {
            int nr = r + direct[0];
            int nc = c + direct[1];

            if (!(nr >= 0 && nc >= 0 && nr < num_r && nc < num_c) ||
                board[nr][nc] == 0) {
                continue;
            }

            res = runBacktracking(
                board, nr, nc, num_r, num_c, word, index + 1, bound);
            if (res) {
                break;
            }
        }

        std::swap(ch, board[r][c]);
        return res;
    }

    std::vector<std::vector<int>> directs;
};
class Solution {
public:
    Solution()
      : directs({
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
      })
    { }

    /**
     * @param init_state: the initial state of chessboard
     * @param final_state: the final state of chessboard
     * @return: return an integer, denote the number of minimum moving
     */
    int minMoveStep(vector<vector<int>> &init_state, vector<vector<int>> &final_state) {
        // # write your code here

        auto src = genStringFromBoard(init_state);
        auto dst = genStringFromBoard(final_state);

        std::queue<std::string> queue;
        queue.push(src);

        std::unordered_set<std::string> visit;
        visit.emplace(std::move(src));

        int step = 0;

        while (!queue.empty()) {
            ++step;
            int size = queue.size();

            for (int i = 0 ; i < size ; ++i) {
                src = queue.front();
                queue.pop();

                for (auto&& state : genNextStates(src)) {
                    if (state == dst) {
                        return step;
                    }

                    if (visit.count(state) == 0) {
                        queue.push(state);
                        visit.emplace(state);
                    }
                }
            }
        }

        return -1;
    }

private:
    std::string genStringFromBoard(const std::vector<std::vector<int>>& board) {

        std::string encode;

        for (int i = 0 ; i < 3 ; ++i) {
            for (int j = 0 ; j < 3 ; ++j) {
                encode.push_back(static_cast<char>(board[i][j] + '0'));
            }
        }

        return encode;
    }

    std::vector<std::string> genNextStates(const std::string& src) {

        std::vector<std::string> dsts;

        int pos = src.find('0');
        int x = pos / 3;
        int y = pos % 3;

        for (const auto& direct : directs) {
            int nx = x + direct[0];
            int ny = y + direct[1];

            if (!(nx >= 0 && nx < 3 && ny >= 0 && ny < 3)) {
                continue;
            }

            int npos = nx * 3 + ny;
            std::string dst(src);
            std::swap(dst[pos], dst[npos]);

            dsts.emplace_back(std::move(dst));
        }

        return dsts;
    }

    std::vector<std::vector<int>> directs;
};


class Solution {
public:
    Solution()
      : directs({{1, 0}, {-1, 0}, {0, 1}, {0, -1}})
    { }

    /**
     * @param init_state: the initial state of chessboard
     * @param final_state: the final state of chessboard
     * @return: return an integer, denote the number of minimum moving
     */
    int minMoveStep(vector<vector<int>> &init_state, vector<vector<int>> &final_state) {
        // # write your code here

        auto init = toString(init_state);
        auto final = toString(final_state);

        std::queue<std::string> queue;
        queue.push(init);

        std:unordered_set<std::string> visit;
        visit.insert(init);

        int step = 0;

        while (!queue.empty()) {

            ++step;
            int n = queue.size();
            for (int i = 0 ; i < n ; ++i) {
                auto src = queue.front();
                queue.pop();

                int index = 0;
                while (index < 9 && src[index] != '0') {
                    ++index;
                }

                auto res = div(index, 3);
                int r = res.quot;
                int c = res.rem;

                for (const auto& direct : directs) {
                    int nr = r + direct[0];
                    int nc = c + direct[1];

                    if (!(nr >= 0 && nc >= 0 && nr < 3 && nc < 3)) {
                        continue;
                    }

                    int new_index = nr * 3 + nc;
                    std::swap(src[index], src[new_index]);

                    if (visit.count(src) == 1) {
                        std::swap(src[index], src[new_index]);
                        continue;
                    }

                    if (src == final) {
                        return step;
                    }

                    visit.insert(src);
                    queue.push(src);
                    std::swap(src[index], src[new_index]);
                }
            }
        }

        return -1;
    }

private:
    std::vector<std::vector<int>> directs;

    std::string toString(auto& board) {

        std::string encode;

        for (int i = 0 ; i < 3 ; ++i) {
            for (int j = 0 ; j < 3 ; ++j) {
                encode.push_back(static_cast<char>(board[i][j] + '0'));
            }
        }

        return encode;
    }
};
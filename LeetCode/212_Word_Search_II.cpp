
struct TrieNode {
    bool is_word;
    std::unordered_map<char, std::shared_ptr<TrieNode>> branch;

    TrieNode()
      : is_word(false)
    { }
};


class Solution {
public:
    Solution()
      : root(std::make_shared<TrieNode>()),
        directs({
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}
        })
    { }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

        int num_r = board.size();
        if (num_r == 0) {
            return {};
        }

        int num_c = board[0].size();
        if (num_c == 0) {
            return {};
        }

        makeTrie(words);

        std::string prefix;
        std::unordered_set<std::string> set;

        for (int r = 0 ; r < num_r ; ++r) {
            for (int c = 0 ; c < num_c ; ++c) {

                char ch = board[r][c];
                if (root->branch.count(ch) == 0) {
                    continue;
                }

                prefix.push_back(ch);
                board[r][c] = 0;

                scanMatrix(r, c, num_r, num_c, board, prefix, root->branch[ch], set);

                board[r][c] = ch;
                prefix.pop_back();
            }
        }

        std::vector<std::string> ans;
        ans.insert(ans.end(), set.begin(), set.end());
        return ans;
    }


private:
    void makeTrie(const std::vector<std::string>& words) {

        for (const auto& word : words) {

            auto curr = root;
            for (char ch : word) {
                if (curr->branch.count(ch) == 0) {
                    curr->branch.insert(
                        std::make_pair(ch, std::make_shared<TrieNode>()));
                }
                curr = curr->branch[ch];
            }
            curr->is_word = true;
        }
    }

    void scanMatrix(
            int r,
            int c,
            int num_r,
            int num_c,
            std::vector<std::vector<char>>& board,
            std::string& prefix,
            std::shared_ptr<TrieNode> curr,
            std::unordered_set<std::string>& set) {

        if (curr->is_word) {
            set.insert(prefix);
        }

        for (const auto& direct : directs) {
            int nr = r + direct[0];
            int nc = c + direct[1];

            if (!(nr >= 0 && nr < num_r && nc >= 0 && nc < num_c)) {
                continue;
            }

            char ch = board[nr][nc];
            if (curr->branch.count(ch) == 0) {
                continue;
            }

            prefix.push_back(ch);
            board[nr][nc] = 0;

            scanMatrix(nr, nc, num_r, num_c, board, prefix, curr->branch[ch], set);

            board[nr][nc] = ch;
            prefix.pop_back();
        }
    }

    std::shared_ptr<TrieNode> root;
    std::vector<std::vector<int>> directs;
};
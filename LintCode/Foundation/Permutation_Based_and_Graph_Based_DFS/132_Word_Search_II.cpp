
struct TrieNode {
    bool is_word;
    std::unordered_map<char, std::shared_ptr<TrieNode>> children;

    TrieNode()
      : is_word(false)
    { }
};


class Solution {
public:
    Solution()
      : directs({
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
      })
    { }

    /**
     * @param board: A list of lists of character
     * @param words: A list of string
     * @return: A list of string
     */
    vector<string> wordSearchII(vector<vector<char>> &board, vector<string> &words) {
        // write your code here

        auto root = makeTrie(words);

        std::string prefix;
        std::unordered_set<std::string> set;

        int num_r = board.size();
        int num_c = board[0].size();
        for (int r = 0 ; r < num_r ; ++r) {
            for (int c = 0 ; c < num_c ; ++c) {
                scanMatrix(r, c, num_r, num_c, board, root, prefix, set);
            }
        }

        std::vector<std::string> ans;
        ans.insert(ans.end(), set.begin(), set.end());
        return ans;
    }

private:
    std::shared_ptr<TrieNode> makeTrie(const std::vector<std::string>& words) {

        auto root = std::make_shared<TrieNode>();

        for (const auto& word : words) {

            auto curr = root;
            for (char ch : word) {
                if (curr->children.count(ch) == 0) {
                    curr->children[ch] = std::make_shared<TrieNode>();
                }
                curr = curr->children[ch];
            }

            if (curr != root) {
                curr->is_word = true;
            }
        }

        return root;
    }

    void scanMatrix(
            int r,
            int c,
            int num_r,
            int num_c,
            std::vector<std::vector<char>>& board,
            std::shared_ptr<TrieNode> curr,
            std::string& prefix,
            std::unordered_set<std::string>& set) {

        char ch = board[r][c];
        if (curr->children.count(ch) == 0) {
            return;
        }

        prefix.push_back(ch);
        board[r][c] = 0;

        curr = curr->children[ch];
        if (curr->is_word) {
            set.insert(prefix);
        }

        for (const auto& direct : directs) {
            int nr = r + direct[0];
            int nc = c + direct[1];

            if (!(nr >= 0 && nr < num_r && nc >= 0 && nc < num_c)) {
                continue;
            }

            scanMatrix(nr, nc, num_r, num_c, board, curr, prefix, set);
        }

        board[r][c] = ch;
        prefix.pop_back();
    }

private:
    std::vector<std::vector<int>> directs;
};



struct TrieNode {
    std::unordered_map<char, std::shared_ptr<TrieNode>> branch;
    bool is_word;

    TrieNode()
      : is_word(false)
    { }
};


class Solution {
public:
    Solution()
      : directs({{1, 0}, {-1, 0}, {0, 1}, {0, -1}})
    { }

    /**
     * @param board: A list of lists of character
     * @param words: A list of string
     * @return: A list of string
     */
    vector<string> wordSearchII(vector<vector<char>> &board, vector<string> &words) {
        // write your code here

        int num_r = board.size();
        if (num_r == 0) {
            return {};
        }

        int num_c = board[0].size();
        if (num_c == 0) {
            return {};
        }

        auto trie = makeTrie(words);

        std::unordered_set<std::string> set;
        std::string config;

        for (int r = 0 ; r < num_r ; ++r) {
            for (int c = 0 ; c < num_c ; ++c) {
                runBackTracking(trie, r, c, num_r, num_c, board, config, set);
            }
        }

        std::vector<std::string> ans;
        for (const auto& word : set) {
            ans.push_back(word);
        }

        return ans;
    }

private:
    std::shared_ptr<TrieNode> makeTrie(const std::vector<std::string>& words) {

        auto root = std::make_shared<TrieNode>();

        for (const auto& word : words) {

            auto curr = root;
            for (char ch : word) {

                if (curr->branch.count(ch) == 0) {
                    curr->branch[ch] = std::make_shared<TrieNode>();
                }
                curr = curr->branch[ch];
            }

            curr->is_word = true;
        }

        return root;
    }


    void runBackTracking(
            std::shared_ptr<TrieNode> curr,
            int r, int c,
            int num_r, int num_c,
            std::vector<std::vector<char>>& board,
            std::string& config,
            std::unordered_set<std::string>& set) {

        char ch = board[r][c];

        if (curr->branch.count(ch) == 0) {
            return;
        }
        curr = curr->branch[ch];

        config.push_back(ch);
        board[r][c] = 0;

        if (curr->is_word) {
            set.insert(config);
        }

        for (const auto& direct : directs) {
            int nr = r + direct[0];
            int nc = c + direct[1];

            if (!(nr >= 0 && nc >= 0 && nr < num_r && nc < num_c) ||
                board[nr][nc] == 0) {
                continue;
            }

            runBackTracking(curr, nr, nc, num_r, num_c, board, config, set);
        }

        config.pop_back();
        board[r][c] = ch;
    }


    std::vector<std::vector<int>> directs;
};
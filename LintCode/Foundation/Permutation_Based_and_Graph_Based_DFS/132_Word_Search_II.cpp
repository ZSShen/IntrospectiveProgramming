
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
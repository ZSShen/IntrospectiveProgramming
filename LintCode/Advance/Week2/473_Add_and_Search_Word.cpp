

struct TrieNode {
    bool is_word;
    std::unordered_map<char, std::shared_ptr<TrieNode>> branch;

    TrieNode()
      : is_word(false)
    { }
};


class WordDictionary {
public:
    WordDictionary()
      : root(std::make_shared<TrieNode>())
    { }

    /*
     * @param word: Adds a word into the data structure.
     * @return: nothing
     */
    void addWord(string &word) {
        // write your code here

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

    /*
     * @param word: A word could contain the dot character '.' to represent any one letter.
     * @return: if the word is in the data structure.
     */
    bool search(string &word) {
        // write your code here

        int len = word.length();
        if (len == 0) {
            return true;
        }

        std::queue<std::pair<std::shared_ptr<TrieNode>, int>> queue;
        queue.push(std::make_pair(root, 0));

        while (!queue.empty()) {
            auto front = queue.front();
            queue.pop();

            auto curr = front.first;
            int idx = front.second;
            if (idx == len && curr->is_word) {
                return true;
            }

            char ch = word[idx];
            if (ch != '.') {
                if (curr->branch.count(ch) == 1) {
                    queue.push(std::make_pair(curr->branch[ch], idx + 1));
                }
            } else {
                for (const auto& pair : curr->branch) {
                    queue.push(std::make_pair(pair.second, idx + 1));
                }
            }
        }

        return false;
    }

private:
    std::shared_ptr<TrieNode> root;
};
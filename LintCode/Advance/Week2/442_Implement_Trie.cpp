
struct TrieNode {
    bool is_word;
    std::unordered_map<char, std::shared_ptr<TrieNode>> branch;

    TrieNode()
      : is_word(false)
    { }
};


class Trie {
public:
    Trie()
      : root(std::make_shared<TrieNode>()) {
        // do intialization if necessary
    }

    /*
     * @param word: a word
     * @return: nothing
     */
    void insert(string &word) {
        // write your code here

        auto curr = root;

        for (char ch : word) {
            if (curr->branch.count(ch) == 0) {
                curr->branch[ch] = std::make_shared<TrieNode>();
            }
            curr = curr->branch[ch];
        }

        curr->is_word = true;
    }

    /*
     * @param word: A string
     * @return: if the word is in the trie.
     */
    bool search(string &word) {
        // write your code here

        auto curr = root;

        for (char ch : word) {
            if (curr->branch.count(ch) == 0) {
                return false;
            }
            curr = curr->branch[ch];
        }

        return curr->is_word;
    }

    /*
     * @param prefix: A string
     * @return: if there is any word in the trie that starts with the given prefix.
     */
    bool startsWith(string &prefix) {
        // write your code here

        auto curr = root;

        for (char ch : prefix) {
            if (curr->branch.count(ch) == 0) {
                return false;
            }
            curr = curr->branch[ch];
        }

        return true;
    }

private:
    std::shared_ptr<TrieNode> root;
};
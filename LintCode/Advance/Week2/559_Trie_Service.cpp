/**
 * Definition of TrieNode:
 * class TrieNode {
 * public:
 *     TrieNode() {}
 *     map<char, TrieNode*> children;
 *     vector<int> top10;
 * };
 */
class TrieService {
private:
    TrieNode* root;

public:
    TrieService() {
        root = new TrieNode();
    }

    TrieNode* getRoot() {
        // Return root of trie root, and
        // lintcode will print the tree struct.
        return root;
    }

    void insert(string& word, int frequency) {
        // Write your code here

        auto curr = root;

        for (char ch : word) {
            if (curr->children.count(ch) == 0) {
                curr->children[ch] = new TrieNode();
            }
            curr = curr->children[ch];

            insertFrequency(curr->top10, frequency);
        }
    }

private:
    void insertFrequency(std::vector<int>& top10, int freq) {

        top10.push_back(freq);

        int n = top10.size();
        for (int i = n - 2 ; i >= 0 ; --i) {
            if (top10[i] < top10[i + 1]) {
                std::swap(top10[i], top10[i + 1]);
            } else {
                break;
            }
        }

        if (n > 10) {
            top10.pop_back();
        }
    }
};


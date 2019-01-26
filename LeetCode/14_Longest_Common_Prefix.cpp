```
struct TrieNode {

    bool isWord;
    std::unordered_map<char, std::shared_ptr<TrieNode>> children;

    TrieNode(bool isWord)
        : isWord(isWord) { }

	~TrieNode() = default;
};


class Trie {

public:
    Trie()
        : root_(std::make_shared<TrieNode>(false)) { }

    ~Trie() = default;

    void addWord(const std::string& word) {

        auto curr = root_;
        auto pred = curr;

        for (char ch : word) {
            auto iter = curr->children.find(ch);
            if (iter == curr->children.end()) {
                pred = curr;
                curr = std::make_shared<TrieNode>(false);
                pred->children.insert(
                    std::make_pair(ch, curr));
                continue;
            }

            pred = curr;
            curr = iter->second;
        }

        curr->isWord = true;
    }

    std::string getLongestCommonPrefix() {

        auto curr = root_;
        std::string prefix;

        while (true) {
            int size = curr->children.size();

			/*
				abc
				abd  => ab
				abe
			*/
            if (size == 0 || size > 1) {
                break;
            }

			/*
				abc
				abcd    => abc
				abcde
			*/
            if (curr->isWord) {
                break;
            }

            for (auto& pair : curr->children) {
                prefix.push_back(pair.first);
                curr = pair.second;
                break;
            }
        }

        return prefix;
    }

private:
    std::shared_ptr<TrieNode> root_;
};


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        Trie trie;
        for (const auto& str : strs) {
            trie.addWord(str);
        }

        return trie.getLongestCommonPrefix();
    }
};
```
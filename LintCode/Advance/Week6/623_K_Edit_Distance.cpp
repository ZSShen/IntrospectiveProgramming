

struct TrieNode {
    bool is_word = false;
    std::unordered_map<char, std::shared_ptr<TrieNode>> branch;
    std::string word;
};


class Solution {
public:
    /**
     * @param words: a set of stirngs
     * @param target: a target string
     * @param k: An integer
     * @return: output all the strings that meet the requirements
     */
    vector<string> kDistance(vector<string> &words, string &target, int k) {
        // write your code here

        auto trie = buildTrie(words);

        int n = target.length();

        std::vector<int> dp(n + 1, 0);
        for (int i = 1 ; i <= n ; ++i) {
            dp[i] = i;
        }

        std::vector<std::string> ans;
        runPreOrder(trie, dp, ans, n, k, target);
        return ans;
    }

private:
    std::shared_ptr<TrieNode> buildTrie(const auto& words) {

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
            curr->word = word;
        }

        return root;
    }

    void runPreOrder(
        auto root, const auto& dp, auto& ans, int n, int k, const auto& target) {

        if (root->is_word && dp[n] <= k) {
            ans.push_back(root->word);
        }

        /**
         * level1: 111111
         * level2: 222222
         *
         *
         * dp[i][j] = MIN | dp[i - 1][j] + 1
         *                | dp[i][j - 1] + 1
         *                | dp[i - 1][j - 1] + 1
         *                | dp[i - 1][j - 1], if s[i] == t[j]
         */

        for (auto& pair : root->branch) {
            char ch = pair.first;
            auto child = pair.second;

            std::vector<int> dp_new(n + 1, 0);

            for (int i = 0 ; i <= n ; ++i) {
                dp_new[i] = dp[i] + 1;
            }
            for (int i = 1 ; i <= n ; ++i) {
                dp_new[i] = std::min(dp_new[i], dp_new[i - 1] + 1);
                dp_new[i] = std::min(dp_new[i], dp[i - 1] + 1);
                if (ch == target[i - 1]) {
                    dp_new[i] = std::min(dp_new[i], dp[i - 1]);
                }
            }

            runPreOrder(child, dp_new, ans, n, k, target);
        }
    }
};
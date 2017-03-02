/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        std::vector<int> ans;
        if (!root) {
            return ans;
        }

        std::queue<std::pair<TreeNode*, int>> bfs;
        bfs.push(std::make_pair(root, 0));

        int traceLevel = 0;
        int max = INT_MIN;
        while (!bfs.empty()) {
            const auto& src = bfs.front();
            TreeNode* current = src.first;
            int currentLevel = src.second;

            if (currentLevel > traceLevel) {
                ++traceLevel;
                ans.push_back(max);
                max = current->val;
            } else {
                if (current->val > max) {
                    max = current->val;
                }
            }

            if (current->left) {
                bfs.push(std::make_pair(current->left, currentLevel + 1));
            }
            if (current->right) {
                bfs.push(std::make_pair(current->right, currentLevel + 1));
            }
            bfs.pop();
        }
        ans.push_back(max);

        return ans;
    }
};
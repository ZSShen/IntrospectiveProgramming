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
    vector<int> rightSideView(TreeNode* root) {

        std::vector<int> ans;
        if (!root) {
            return ans;
        }

        std::queue<TreeNode*> queue;
        queue.push(root);
        ans.push_back(root->val);

        while (!queue.empty()) {

            std::queue<TreeNode*> temp;
            while (!queue.empty()) {
                auto curr = queue.front();
                queue.pop();

                if (curr->left) {
                    temp.push(curr->left);
                }
                if (curr->right) {
                    temp.push(curr->right);
                }
            }

            if (!temp.empty()) {
                ans.push_back(temp.back()->val);
            }
            queue = std::move(temp);
        }

        return ans;
    }
};
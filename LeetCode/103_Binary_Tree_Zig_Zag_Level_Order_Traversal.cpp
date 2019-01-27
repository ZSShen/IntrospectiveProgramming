/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
enum Direct {
    R,
    L
};


class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        std::vector<std::vector<int>> ans;
        if (!root) {
            return ans;
        }

        std::stack<TreeNode*> stack;
        stack.push(root);
        ans.push_back(std::vector<int>(1, root->val));

        int direct = Direct::R;

        while (!stack.empty()) {
            std::vector<int> level;
            std::stack<TreeNode*> collect;

            if (direct == Direct::R) {
                while (!stack.empty()) {
                    auto curr = stack.top();
                    stack.pop();

                    if (curr->right) {
                        collect.push(curr->right);
                        level.push_back(curr->right->val);
                    }
                    if (curr->left) {
                        collect.push(curr->left);
                        level.push_back(curr->left->val);
                    }
                }

                direct = Direct::L;
            } else {
                while (!stack.empty()) {
                    auto curr = stack.top();
                    stack.pop();

                    if (curr->left) {
                        collect.push(curr->left);
                        level.push_back(curr->left->val);
                    }
                    if (curr->right) {
                        collect.push(curr->right);
                        level.push_back(curr->right->val);
                    }
                }

                direct = Direct::R;
            }

            if (!collect.empty()) {
                stack = std::move(collect);
                ans.push_back(std::move(level));
            }
        }

        return ans;
    }
};
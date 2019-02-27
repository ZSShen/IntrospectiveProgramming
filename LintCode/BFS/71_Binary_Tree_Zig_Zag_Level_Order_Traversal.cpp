/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: A Tree
     * @return: A list of lists of integer include the zigzag level order traversal of its nodes' values.
     */
    vector<vector<int>> zigzagLevelOrder(TreeNode * root) {
        // write your code here

        std::vector<std::vector<int>> ans;
        if (!root) {
            return ans;
        }

        std::stack<TreeNode*> stack;
        stack.push(root);
        int level = 0;

        while (!stack.empty()) {
            int size = stack.size();
            std::vector<int> collect;
            std::stack<TreeNode*> shadow;

            for (int i = 0 ; i < size ; ++i) {
                auto curr = stack.top();
                stack.pop();

                if (level >> 1 << 1 == level) {
                    if (curr->left) {
                        shadow.push(curr->left);
                    }
                    if (curr->right) {
                        shadow.push(curr->right);
                    }
                } else {
                    if (curr->right) {
                        shadow.push(curr->right);
                    }
                    if (curr->left) {
                        shadow.push(curr->left);
                    }
                }

                collect.push_back(curr->val);
            }

            ++level;
            stack = std::move(shadow);
            ans.push_back(std::move(collect));
        }

        return ans;
    }
};
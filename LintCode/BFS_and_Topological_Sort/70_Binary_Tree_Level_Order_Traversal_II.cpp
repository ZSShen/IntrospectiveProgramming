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
     * @param root: A tree
     * @return: buttom-up level order a list of lists of integer
     */
    vector<vector<int>> levelOrderBottom(TreeNode * root) {
        // write your code here

        std::vector<std::vector<int>> ans;
        if (!root) {
            return ans;
        }

        std::queue<TreeNode*> queue;
        queue.push(root);

        while (!queue.empty()) {
            int size = queue.size();
            std::vector<int> level;

            for (int i = 0 ; i < size ; ++i) {
                auto curr = queue.front();
                queue.pop();

                if (curr->left) {
                    queue.push(curr->left);
                }
                if (curr->right) {
                    queue.push(curr->right);
                }

                level.push_back(curr->val);
            }

            ans.push_back(std::move(level));
        }

        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};
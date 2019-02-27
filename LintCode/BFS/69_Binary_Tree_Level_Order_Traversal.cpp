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
     * @return: Level order a list of lists of integer
     */
    vector<vector<int>> levelOrder(TreeNode * root) {
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
                auto node = queue.front();
                queue.pop();

                if (node->left) {
                    queue.push(node->left);
                }
                if (node->right) {
                    queue.push(node->right);
                }

                level.push_back(node->val);
            }

            ans.push_back(std::move(level));
        }

        return ans;
    }
};
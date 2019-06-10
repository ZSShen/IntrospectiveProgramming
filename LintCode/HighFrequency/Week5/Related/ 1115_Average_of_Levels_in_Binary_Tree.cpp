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
     * @param root: the binary tree of the  root
     * @return: return a list of double
     */
    vector<double> averageOfLevels(TreeNode * root) {
        // write your code here

        if (!root) {
            return {};
        }

        std::vector<double> ans;

        std::queue<TreeNode*> queue;
        queue.push(root);

        while (!queue.empty()) {
            int size = queue.size();
            double avg = 0;

            for (int i = 0 ; i < size ; ++i) {
                auto front = queue.front();
                queue.pop();

                if (front->left) {
                    queue.push(front->left);
                }
                if (front->right) {
                    queue.push(front->right);
                }

                avg += front->val;
            }

            avg /= size;
            ans.push_back(avg);
        }

        return ans;
    }
};

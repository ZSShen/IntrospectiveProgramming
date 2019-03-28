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
     * @param root: the root of the binary tree
     * @return: all root-to-leaf paths
     */
    vector<string> binaryTreePaths(TreeNode * root) {
        // write your code here

        std::vector<std::string> ans;
        if (!root) {
            return ans;
        }

        std::vector<int> path;
        runPreOrder(root, path, ans);
        return ans;
    }

private:
    void runPreOrder(
            TreeNode* root,
            std::vector<int>& path,
            std::vector<std::string>& ans) {

        path.push_back(root->val);

        if (!root->left && !root->right) {
            std::stringstream stream;
            for (auto val : path) {
                stream << val << "->";
            }
            auto str = stream.str();
            str.pop_back();
            str.pop_back();
            ans.push_back(std::move(str));
        }

        if (root->left) {
            runPreOrder(root->left, path, ans);
        }
        if (root->right) {
            runPreOrder(root->right, path, ans);
        }

        path.pop_back();
    }
};
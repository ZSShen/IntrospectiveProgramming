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
     * @param root: the root of binary tree
     * @return: new root
     */
    TreeNode * upsideDownBinaryTree(TreeNode * root) {
        // write your code here

        /**
         *   1 - 3     1             4
         *   |         |            / \
         *   2 - 5  => 2 - 3  =>   5   2
         *   |         |              / \
         *   4         4 - 5         3   1
         *
         */

        if (!root) {
            return nullptr;
        }

        return runPreorder(root, nullptr, nullptr);
    }

private:
    TreeNode* runPreorder(
            TreeNode* curr, TreeNode* parent, TreeNode* sibling) {

        TreeNode* new_root = nullptr;

        if (curr->left) {
            new_root = runPreorder(curr->left, curr, curr->right);
        }

        if (!new_root) {
            new_root = curr;
        }

        curr->left = sibling;
        curr->right = parent;

        return new_root;
    }
};


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
     * @param root: the root of binary tree
     * @return: new root
     */
    TreeNode * upsideDownBinaryTree(TreeNode * root) {
        // write your code here

        if (!root) {
            return nullptr;
        }

        return runPreorder(root);
    }


private:
    TreeNode* runPreorder(TreeNode* root) {

        if (!root->left) {
            return root;
        }

        auto new_root = runPreorder(root->left);

        root->left->right = root;
        root->left->left = root->right;

        root->left = root->right = nullptr;

        return new_root;
    }
};

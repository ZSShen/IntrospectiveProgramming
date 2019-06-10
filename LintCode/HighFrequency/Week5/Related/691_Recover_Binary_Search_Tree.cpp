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
     * @param root: the given tree
     * @return: the tree after swapping
     */
    TreeNode * bstSwappedNode(TreeNode * root) {
        // write your code here

        TreeNode *pred = nullptr, *first = nullptr, *second = nullptr;

        runInOrder(root, pred, first, second);

        if (first && second) {
            std::swap(first->val, second->val);
        }

        return root;
    }

private:
    void runInOrder(
            TreeNode* root,
            TreeNode*& pred,
            TreeNode*& first,
            TreeNode*& second) {

        if (root->left) {
            runInOrder(root->left, pred, first, second);
        }

        if (pred && root->val < pred->val) {
            if (!first) {
                first = pred;
            }
            if (first) {
                second = root;
            }
        }
        pred = root;

        if (root->right) {
            runInOrder(root->right, pred, first, second);
        }
    }
};
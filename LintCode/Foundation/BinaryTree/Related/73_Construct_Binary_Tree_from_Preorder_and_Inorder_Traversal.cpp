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
     *@param preorder : A list of integers that preorder traversal of a tree
     *@param inorder : A list of integers that inorder traversal of a tree
     *@return : Root of a tree
     */
    TreeNode * buildTree(vector<int> &preorder, vector<int> &inorder) {
        // write your code here

        /**
         *  PreOrder: Root (left Branch) (Right Branch)
         *  InOrder : (Left Branch) Root (Right Branch)
         *
         *       1                    T     L        R
         *     /   \        PreOrder: 1, 2, 4, 5, 3, 6, 7
         *    2     3                    -------  -------
         *   / \   / \                   L     T     R
         *  4   5 6   7     InOrder : 4, 2, 5, 1, 6, 3, 7
         *                            -------     -------
         */

        int num_pre = preorder.size();
        int num_in = inorder.size();

        if (num_pre == 0 || num_in == 0 || num_pre != num_in) {
            return nullptr;
        }

        return buildTree(preorder, 0, num_pre - 1, inorder, 0, num_in - 1);
    }

private:
    TreeNode* buildTree(
            const auto& preorder, int pre_bgn, int pre_end,
            const auto& inorder, int in_bgn, int in_end) {

        if (in_bgn > in_end) {
            return nullptr;
        }

        if (in_bgn == in_end) {
            return new TreeNode(inorder[in_bgn]);
        }

        int root_val = preorder[pre_bgn];
        int mid;
        for (mid = in_bgn ; mid <= in_end ; ++mid) {
            if (inorder[mid] == root_val) {
                break;
            }
        }

        int left_range = mid - in_bgn;

        auto root = new TreeNode(root_val);
        root->left = buildTree(
            preorder, pre_bgn + 1, pre_bgn + left_range,
            inorder, in_bgn, mid - 1);
        root->right = buildTree(
            preorder, pre_bgn + 1 + left_range, pre_end,
            inorder, mid + 1, in_end);

        return root;
    }
};

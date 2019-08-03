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
     * @param inorder: A list of integers that inorder traversal of a tree
     * @param postorder: A list of integers that postorder traversal of a tree
     * @return: Root of a tree
     */
    TreeNode * buildTree(vector<int> &inorder, vector<int> &postorder) {
        // write your code here

        /**
         * PostOrder: (Left Branch) (Right Branch) Root
         * InOrder  : (Left Branch) Root (Right Branch)
         *
         *       1                        L        R     T
         *     /   \        PostOrder: 4, 5, 2, 6, 7, 3, 1
         *    2     3                  -------  -------
         *   / \   / \                    L     T     R
         *  4   5 6   7     InOrder  : 4, 2, 5, 1, 6, 3, 7
         *                             -------     -------
         */

        int num_in = inorder.size();
        int num_post = postorder.size();

        if (num_in == 0 || num_post == 0 || num_in != num_post) {
            return nullptr;
        }

        return buildTree(inorder, 0, num_in - 1, postorder, 0, num_post - 1);
    }

private:
    TreeNode* buildTree(
            const auto& inorder, int in_bgn, int in_end,
            const auto& postorder, int post_bgn, int post_end) {

        if (in_end < in_bgn) {
            return nullptr;
        }

        if (in_bgn == in_end) {
            return new TreeNode(inorder[in_bgn]);
        }

        int root_val = postorder[post_end];

        int mid;
        for (mid = in_bgn ; mid <= in_end ; ++mid) {
            if (inorder[mid] == root_val) {
                break;
            }
        }

        int left_range = mid - in_bgn;

        auto root = new TreeNode(root_val);
        root->left = buildTree(
            inorder, in_bgn, mid - 1,
            postorder, post_bgn, post_bgn + left_range - 1);
        root->right = buildTree(
            inorder, mid + 1, in_end,
            postorder, post_bgn + left_range, post_end - 1);

        return root;
    }
};
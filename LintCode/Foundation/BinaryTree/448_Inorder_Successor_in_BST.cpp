/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


class Solution {
public:
    /*
     * @param root: The root of the BST.
     * @param p: You need find the successor node of p.
     * @return: Successor of p.
     */
    TreeNode * inorderSuccessor(TreeNode * root, TreeNode * p) {
        // write your code here

        /**
         *  Case 1.
         *          a
         *           \
         *            b
         *           / \
         *          /   \
         *         /_____\
         *
         *  Case 2.
         *        /\
         *       /  \
         *      /____\
         *      \
         *       b
         *      /
         *     a
         */

        if (!root || !p) {
            return nullptr;
        }

        if (p->right) {
            // Case 1.

            p = p->right;
            while (p->left) {
                p = p->left;
            }

            return p;
        }

        // Case 2.
        TreeNode* turn = nullptr;
        auto curr = root;
        while (curr != p) {
            if (p->val < curr->val) {
                turn = curr;
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }

        return turn;
    }
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


class Solution {
public:
    /*
     * @param root: The root of the BST.
     * @param p: You need find the successor node of p.
     * @return: Successor of p.
     */
    TreeNode * inorderSuccessor(TreeNode * root, TreeNode * p) {
        // write your code here

        if (!root || !p) {
            return nullptr;
        }

        if (p->val >= root->val) {
            return inorderSuccessor(root->right, p);
        } else {
            auto res = inorderSuccessor(root->left, p);
            return (res != nullptr) ? res : root;
        }
    }
};
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

        if (p->right) {
            // Case 1.
            auto curr = p->right;
            while (curr->left) {
                curr = curr->left;
            }
            return curr;
        } else {
            // Case 2.
            TreeNode* turn = nullptr;
            auto curr = root;
            while (curr != p) {
                if (curr->val > p->val) {
                    // Left turn.
                    turn = curr;
                    curr = curr->left;
                } else {
                    curr = curr->right;
                }
            }
            return turn;
        }
    }
};
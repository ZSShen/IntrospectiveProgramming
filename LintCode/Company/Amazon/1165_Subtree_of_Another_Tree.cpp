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
     * @param s: the s' root
     * @param t: the t' root
     * @return: whether tree t has exactly the same structure and node values with a subtree of s
     */
    bool isSubtree(TreeNode * s, TreeNode * t) {
        // Write your code here

        if (!s && !t) {
            return true;
        }
        if (!s || !t) {
            return false;
        }

        return runPreOrder(s, t);
    }

private:
    bool runPreOrder(TreeNode* s, TreeNode* t) {

        if (s->val == t->val) {
            bool res = matchTree(s, t);
            if (res) {
                return true;
            }
        }

        if (s->left) {
            bool res = runPreOrder(s->left, t);
            if (res) {
                return true;
            }
        }

        if (s->right) {
            bool res = runPreOrder(s->right, t);
            if (res) {
                return true;
            }
        }

        return false;
    }


    bool matchTree(TreeNode* s, TreeNode* t) {

        if (!s || !t) {
            return s == t;
        }

        if (s->val != t->val) {
            return false;
        }

        bool res = matchTree(s->left, t->left);
        if (!res) {
            return false;
        }

        return matchTree(s->right, t->right);
    }
};
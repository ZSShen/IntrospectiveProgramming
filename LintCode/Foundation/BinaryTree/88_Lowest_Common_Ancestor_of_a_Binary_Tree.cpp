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
    /*
     * @param root: The root of the binary search tree.
     * @param A: A TreeNode in a Binary.
     * @param B: A TreeNode in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
    TreeNode * lowestCommonAncestor(TreeNode * root, TreeNode * A, TreeNode * B) {
        // write your code here

        /**
         *  Postorder Traversal
         *  Note that this solution only works when A and B can be found.
         */

        if (!root) {
            return nullptr;
        }

        if (root == A || root == B) {
            return root;
        }

        auto l = lowestCommonAncestor(root->left, A, B);
        auto r = lowestCommonAncestor(root->right, A, B);

        if (l && r) {
            return root;
        }

        if (l) {
            return l;
        }

        if (r) {
            return r;
        }
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


struct Record {
    bool found_a;
    bool found_b;
    TreeNode* lca;

    Record()
      : found_a(false), found_b(false), lca(nullptr)
    { }

    Record(bool found_a, bool found_b, TreeNode* lca)
      : found_a(found_a), found_b(found_b), lca(lca)
    { }
};


class Solution {
public:
    /*
     * @param root: The root of the binary search tree.
     * @param A: A TreeNode in a Binary.
     * @param B: A TreeNode in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
    TreeNode * lowestCommonAncestor(TreeNode * root, TreeNode * A, TreeNode * B) {
        // write your code here

        auto res = runPostOrder(root, A, B);
        return res.lca;
    }

private:
    Record runPostOrder(TreeNode* root, TreeNode* A, TreeNode* B) {

        if (!root) {
            return Record();
        }

        Record curr;
        if (root == A) {
            curr.found_a = true;
        }
        if (root == B) {
            curr.found_b = true;
        }

        auto l = runPostOrder(root->left, A, B);
        if (l.lca) {
            return l;
        }

        auto r = runPostOrder(root->right, A, B);
        if (r.lca) {
            return r;
        }

        curr.found_a = curr.found_a || l.found_a || r.found_a;
        curr.found_b = curr.found_b || l.found_b || r.found_b;

        if (curr.found_a && curr.found_b) {
            curr.lca = root;
            return curr;
        }

        return curr;
    }
};

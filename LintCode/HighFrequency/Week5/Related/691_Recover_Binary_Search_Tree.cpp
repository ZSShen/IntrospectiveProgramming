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

        /**
         *  Apply inorder traversal to finde the inversed number pairs.
         *
         *  Specifically, we use 2 pointers curr and pred, which is the inorder
         *  predecessor of curr, to traverse the tree. For the first time,
         *  if we find out an inversed number pair, namely pred > curr, we record
         *  pred. For the second time, if we discover another inversed number
         *  pair, we record curr.
         *
         *    *     *
         *  1 5 3 4 2  => 5 > 3 => (5, 2)
         *  1 2 3 4 5     4 > 2
         *
         *  *     *    => 4 > 2 => (4, 1)
         *  4 2 3 1 5     3 > 1
         *  1 2 3 4 5
         *
         */

        TreeNode *pred = nullptr, *src = nullptr, *dst = nullptr;
        runInOrder(root, pred, src, dst);

        if (src && dst) {
            std::swap(src->val, dst->val);
        }

        return root;
    }

private:
    void runInOrder(
        TreeNode* curr, TreeNode*& pred, TreeNode*& src, TreeNode*& dst) {

        if (curr->left) {
            runInOrder(curr->left, pred, src, dst);
        }

        if (pred && pred->val > curr->val) {
            if (!src) {
                src = pred;
            }
            if (src) {
                dst = curr;
            }

            /**
             *  This is wrong!
             *  Consider the trival case like {1, 3, 4}.
             *
             *  if (!src) {
             *      src = pred;
             *  } else {
             *      dst = curr;
             *  }
             *
             */
        }
        pred = curr;

        if (curr->right) {
            runInOrder(curr->right, pred, src, dst);
        }
    }
};
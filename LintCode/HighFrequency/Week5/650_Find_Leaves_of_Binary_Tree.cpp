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
     * @param root: the root of binary tree
     * @return: collect and remove all leaves
     */
    vector<vector<int>> findLeaves(TreeNode * root) {
        // write your code here

        /**
         *         1(3)
         *        / \
         *    (2)2   3(1)
         *      / \
         *  (1)4   5(1)
         *
         *   1: 4, 5, 3
         *   2: 2
         *   3: 1
         */

        std::unordered_map<int, std::vector<int>> map;
        int h = runPostOrder(root, map);

        std::vector<std::vector<int>> ans;
        for (int i = 1 ; i <= h ; ++i) {
            ans.emplace_back(std::move(map[i]));
        }

        return ans;
    }

private:
    int runPostOrder(TreeNode* root, auto& map) {

        if (!root) {
            return 0;
        }

        int l = runPostOrder(root->left, map);
        int r = runPostOrder(root->right, map);

        int h = std::max(l, r) + 1;
        map[h].push_back(root->val);

        return h;
    }
};
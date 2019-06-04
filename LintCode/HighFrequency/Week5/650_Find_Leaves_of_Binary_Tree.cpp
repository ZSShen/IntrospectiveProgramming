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

        /**       (3)
         *         1
         *        / \
         *    (2)2   3(1)
         *      / \
         *  (1)4   5(1)
         *
         *  (1) 4 5 3
         *  (2) 2
         *  (3) 1
         */

        if (!root) {
            return {};
        }

        std::unordered_map<int, std::vector<int>> map;
        int height = findHeights(root, map);

        std::vector<std::vector<int>> ans;
        for (int i = 1 ; i <= height ; ++i) {
            ans.emplace_back(std::move(map[i]));
        }

        return ans;
    }

private:
    int findHeights(
            TreeNode* root,
            std::unordered_map<int, std::vector<int>>& map) {

        if (!root) {
            return 0;
        }

        int l = findHeights(root->left, map);
        int r = findHeights(root->right, map);

        int height = std::max(l, r) + 1;
        map[height].push_back(root->val);

        return height;
    }
};
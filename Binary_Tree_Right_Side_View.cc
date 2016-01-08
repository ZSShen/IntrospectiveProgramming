
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
    vector<int> rightSideView(TreeNode* root)
    {
        vector<int> view;
        if (!root)
            return view;

        /* Bootstrap the BFS. */
        queue<Record*> trav;
        Record* rec = new Record(root, 0);
        trav.push(rec);
        size_t level = -1;

        while (!trav.empty()) {
            rec = trav.front();
            size_t cur_level = rec->level_;
            TreeNode* node = rec->node_;

            /* Collect the nodes viewable from right side. */
            if (cur_level != level) {
                level = cur_level;
                view.push_back(node->val);
            }

            /* Enlarge the BFS coverage. */
            if (node->right) {
                rec = new Record(node->right, cur_level + 1);
                trav.push(rec);
            }
            if (node->left) {
                rec = new Record(node->left, cur_level + 1);
                trav.push(rec);
            }

            delete node;
            trav.pop();
        }

        return view;
    }

private:
    struct Record
    {
        TreeNode* node_;
        size_t level_;
        Record(TreeNode* node, size_t level)
          : node_(node),
            level_(level)
        {}
    };
};

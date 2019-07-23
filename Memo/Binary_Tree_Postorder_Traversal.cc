/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> order;
        if (!root)
            return order;

        stack<Frame> stk;
        stk.push(Frame(root, root->val, COLOR_GRAY));
        while (!stk.empty()) {
            Frame& ref = stk.top();
            if (ref.color == COLOR_GRAY) {
                TreeNode* curr = ref.curr;
                if (curr->right)
                    stk.push(Frame(curr->right, curr->right->val, COLOR_GRAY));
                if (curr->left)
                    stk.push(Frame(curr->left, curr->left->val, COLOR_GRAY));
                ref.color = COLOR_BLACK;
            } else {
                order.push_back(ref.node_id);
                stk.pop();
            }
        }

        return order;
    }

private:
    enum {
        COLOR_GRAY,
        COLOR_BLACK
    };

    struct Frame
    {
        Frame(TreeNode* curr, int node_id, char color)
          : color(color),
            node_id(node_id),
            curr(curr)
        {}

        char color;
        int node_id;
        TreeNode* curr;
    };
};
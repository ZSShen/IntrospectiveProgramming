/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root)
    {
        if (!root)
            return string("n");

        /* Bootstrap the serialization. */
        stringstream stream;
        stream << root->val;
        queue<TreeNode*> trav;
        trav.push(root);

        while (!trav.empty()) {
            TreeNode* curr = trav.front();

            /* Serialize the left branch. */
            stream << ',';
            if (curr->left) {
                trav.push(curr->left);
                stream << curr->left->val;
            } else
                stream << 'n';

            /* Serialize the right branch. */
            stream << ',';
            if (curr->right) {
                trav.push(curr->right);
                stream << curr->right->val;
            } else
                stream << 'n';

            trav.pop();
        }

        return stream.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data)
    {
        const char* payload = data.c_str();
        size_t len = strlen(payload);

        /* Early return for trival tree. */
        if (len == 1 && payload[0] == 'n')
            return NULL;

        /* Bootstrap the deserialization. */
        char blah[256];
        size_t bgn = 0, end = 0;
        while (payload[end] != ',')
            ++end;
        size_t count = end - bgn;
        memcpy(blah, payload, count);
        blah[count] = 0;
        bgn = ++end;
        ++end;

        queue<TreeNode*> trav;
        TreeNode* root = new TreeNode(atoi(blah));
        trav.push(root);

        while (!trav.empty()) {
            TreeNode* curr = trav.front();

            /* Deserialize the left branch. */
            while (payload[end] != ',')
                ++end;
            if (payload[bgn] != 'n') {
                count = end - bgn;
                memcpy(blah, payload + bgn, count);
                blah[count] = 0;
                TreeNode* left = new TreeNode(atoi(blah));
                curr->left = left;
                trav.push(left);
            }
            bgn = ++end;
            ++end;

            /* Deserialize the right branch. */
            while ((end < len) && (payload[end] != ','))
                ++end;
            if (payload[bgn] != 'n') {
                count = end - bgn;
                memcpy(blah, payload + bgn, count);
                blah[count] = 0;
                TreeNode* right = new TreeNode(atoi(blah));
                curr->right = right;
                trav.push(right);
            }
            bgn = ++end;
            ++end;

            trav.pop();
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
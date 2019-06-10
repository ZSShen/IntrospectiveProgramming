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
    string serialize(TreeNode* root) {

        if (!root) {
            return "#";
        }

        return std::to_string(root->val) + "," \
                + serialize(root->left) + "," \
                + serialize(root->right);

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        std::stringstream encode(data);
        return deserializeHelper(encode);
    }

private:
    TreeNode* deserializeHelper(std::stringstream& encode) {

        std::string token;
        std::getline(encode, token, ',');
        if (token == "#") {
            return nullptr;
        }

        auto root = new TreeNode(std::stoi(token));
        root->left = deserializeHelper(encode);
        root->right = deserializeHelper(encode);

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
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
    TreeNode* recoverFromPreorder(string str) {

        int len = str.length();
        if (len == 0) {
            return nullptr;
        }
        
        // Construct the root node.
        int end = 0;

        auto num_pair = getNum(str, end, len);
        int num = num_pair.first;
        end = num_pair.second;            
        auto root = new TreeNode(num);
        
        std::unordered_map<int, std::vector<TreeNode*>> memo;
        memo[0].push_back(root);
        
        while (end < len) {
             
			// Get the depth of the current node.
            auto depth_pair = getDepth(str, end, len);
            int depth = depth_pair.first;
            end = depth_pair.second;

			// Get the value of the current node.
            auto num_pair = getNum(str, end, len);
            int num = num_pair.first;
            end = num_pair.second;            
            auto new_node = new TreeNode(num);
            
            memo[depth].push_back(new_node);
            
			// Link the parent-child relationship.
            auto parent = memo[depth - 1].back();
            if (!parent->left) {
                parent->left = new_node;
            } else if (!parent->right) {
                parent->right = new_node;
            }
            
            if (parent->left && parent->right) {
                memo[depth - 1].pop_back();
            }
        }
        
        return root;
    }
    
private:
    std::pair<int, int> getNum(const std::string& str, int bgn, int len) {
        
        int end = bgn;
        while (end < len) {
            if (!('0' <= str[end] && str[end] <= '9')) {
                break;
            }
            ++end;
        }
        --end;

        int num = 0;
        int exp = 1;
        for (int i = end ; i >= bgn ; --i) {
            num += exp * (str[i] - '0');
            exp *= 10;
        }
        
        return std::make_pair(num, end + 1);
    }
    
    std::pair<int, int> getDepth(const std::string& str, int bgn, int len) {
        
        int end = bgn;
        while (end < len) {
            if (str[end] != '-') {
                break;
            }
            ++end;
        }

        return std::make_pair(end - bgn, end);
    }
    
};
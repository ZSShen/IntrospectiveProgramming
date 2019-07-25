class Solution {
public:
    Solution()
      : bound(16)
    { }

    /**
     * @param nums: a list of integers
     * @return: return an integer
     */
    int pathSum(vector<int> &nums) {
        // write your code here

        /**
         *  113 -> depth: 1, position: 1 -> 2 ^ 0 + 0 = 1 -> the 1st node
         *  215 -> depth: 2, position: 1 -> 2 ^ 1 + 0 = 3 -> the 3rd node
         *  ...
         *
         */

        if (nums.empty()) {
            return 0;
        }

        std::vector<int> tree(bound, -1);

        for (int num : nums) {
            int depth = num / 100;
            num -= depth * 100;

            int position = num / 10;
            num -= position * 10;

            int index = pow(2, depth - 1) + (position - 1);
            tree[index] = num;
        }

        int ans = 0;
        runPreOrder(tree, 1, 0, ans);
        return ans;
    }

private:

    void runPreOrder(const auto& tree, int root, int sum, int& ans) {

        sum += tree[root];

        int left = getLeft(root);
        int right = getRight(root);

        bool left_is_null = isNull(tree, left);
        bool right_is_null = isNull(tree, right);

        if (left_is_null && right_is_null) {
            ans += sum;
        }

        if (!left_is_null) {
            runPreOrder(tree, left, sum, ans);
        }
        if (!right_is_null) {
            runPreOrder(tree, right, sum, ans);
        }

        sum -= tree[root];
    }


    int getLeft(int x) {
        return x << 1;
    }

    int getRight(int x) {
        return (x << 1) + 1;
    }

    bool isNull(const auto& tree, int x) {

        if (x >= bound) {
            return true;
        }
        if (tree[x] == -1) {
            return true;
        }

        return false;
    }

    int bound;
};


class Solution {
public:

    /**
     * @param nums: a list of integers
     * @return: return an integer
     */
    int pathSum(vector<int> &nums) {
        // write your code here

        /**
         *  113 -> depth: 1, position: 1 -> 2 ^ 0 + 0 = 1 -> the 1st node
         *  215 -> depth: 2, position: 1 -> 2 ^ 1 + 0 = 3 -> the 3rd node
         *  ...
         *
         *  TODO: Clean the tree after resolving the answer.
         */

        if (nums.empty()) {
            return 0;
        }

        std::unordered_map<int, TreeNode*> map;
        for (int num : nums) {

            int depth = num / 100;
            num -= depth * 100;

            int position = num / 10;
            num -= position * 10;

            int index = pow(2, depth - 1) + (position - 1);

            map[index] = new TreeNode(num);
        }

        for (auto& pair : map) {
            int index = pair.first;
            auto curr = pair.second;

            int l_index = index << 1;
            if (map.count(l_index) == 1) {
                curr->left = map[l_index];
            }

            int r_index = l_index + 1;
            if (map.count(r_index) == 1) {
                curr->right = map[r_index];
            }
        }

        int ans = 0;
        runPreOrder(map[1], 0, ans);
        return ans;
    }

private:
    void runPreOrder(TreeNode* root, int sum, int& ans) {

        sum += root->val;

        if (!root->left && !root->right) {
            ans += sum;
        }

        if (root->left) {
            runPreOrder(root->left, sum, ans);
        }
        if (root->right) {
            runPreOrder(root->right, sum, ans);
        }

        sum -= root->val;
    }
};
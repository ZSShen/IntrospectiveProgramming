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

struct Record
{
    TreeNode *root;
    int level;

    Record(TreeNode *root, int level)
        : root(root),
          level(level)
    {
    }
};

class Solution
{
public:
    /**
     * @param root: the root of tree
     * @return: the vertical order traversal
     */
    vector<vector<int>> verticalOrder(TreeNode *root)
    {
        // write your code here

        /**
         *     (0)
         *      3
         *     / \
         *(-1)9   20(1)
         *       /  \
         *      15   7
         *     (0)   (2)
         */

        if (!root)
        {
            return {};
        }

        std::queue<Record> queue;
        queue.push(Record(root, 0));

        std::map<int, std::vector<int>> groups;

        while (!queue.empty())
        {

            auto record = queue.front();
            queue.pop();

            auto root = record.root;
            int level = record.level;

            if (root->left)
            {
                queue.push(Record(root->left, level - 1));
            }
            if (root->right)
            {
                queue.push(Record(root->right, level + 1));
            }

            groups[level].push_back(root->val);
        }

        std::vector<std::vector<int>> ans;
        for (auto &&pair : groups)
        {
            ans.emplace_back(std::move(pair.second));
        }

        return ans;
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

struct Record
{
    TreeNode *node;
    int level;

    Record(TreeNode *node, int level)
        : node(node), level(level)
    {
    }
};

class Solution
{
public:
    /**
     * @param root: the root of tree
     * @return: the vertical order traversal
     */
    vector<vector<int>> verticalOrder(TreeNode *root)
    {
        // write your code here

        /**
         *     (0)
         *      3
         *     / \
         *(-1)9   20(1)
         *       /  \
         *      15   7
         *     (0)   (2)
         */

        if (!root)
        {
            return {};
        }

        std::unordered_map<int, std::vector<int>> map;

        std::queue<Record> queue;
        queue.push(Record(root, 0));
        int max = -1, min = 1;

        while (!queue.empty())
        {
            auto rec = queue.front();
            queue.pop();

            auto node = rec.node;
            int level = rec.level;

            max = std::max(max, level);
            min = std::min(min, level);

            map[level].push_back(node->val);

            if (node->left)
            {
                queue.push(Record(node->left, level - 1));
            }
            if (node->right)
            {
                queue.push(Record(node->right, level + 1));
            }
        }

        std::vector<std::vector<int>> ans;
        for (int i = min; i <= max; ++i)
        {
            if (map.count(i) == 1)
            {
                ans.emplace_back(std::move(map[i]));
            }
        }

        return ans;
    }
};
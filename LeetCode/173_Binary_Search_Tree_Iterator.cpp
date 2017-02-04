/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root)
        : state(LEFT), peek(root) {
        if (root) {
            path.push(root);
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        peek = treeWalk();
        return peek != nullptr;
    }

    /** @return the next smallest number */
    int next() {
        return peek->val;
    }

private:
    enum {
        LEFT,
        MIDDLE,
        RIGHT,
        UP
    };

private:
    TreeNode* treeWalk() {
        if (path.empty()) {
            return nullptr;
        }

        TreeNode* current = path.top();
        while (true) {
            switch (state) {
                case LEFT: {
                    if (current->left) {
                        current = current->left;
                        path.push(current);
                        continue;
                    }
                    state = MIDDLE;
                }
                case MIDDLE: {
                    state = RIGHT;
                    return current;
                }
                case RIGHT: {
                    if (current->right) {
                        current = current->right;
                        path.push(current);
                        state = LEFT;
                        continue;
                    }
                }
                case UP: {
                    // Backtracking
                    path.pop();
                    if (path.empty()) {
                        return nullptr;
                    }
                    if (current == path.top()->left) {
                        state = MIDDLE;
                    } else {
                        state = UP;
                    }
                    current = path.top();
                    break;
                }
            }
        }
    }

private:
    char state;
    std::stack<TreeNode*> path;
    TreeNode* peek;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
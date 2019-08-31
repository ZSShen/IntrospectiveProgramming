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


struct Record {
    double diff;
    int value;

    Record(double diff, int value)
        : diff(diff), value(value)
    { }
};


struct RecordComparator {

    bool operator() (const Record& rhs, const Record& lhs) {
        return rhs.diff > lhs.diff;
    }
};


class Solution {
public:
    /**
     * @param root: the given BST
     * @param target: the given target
     * @param k: the given k
     * @return: k values in the BST that are closest to the target
     */
    vector<int> closestKValues(TreeNode * root, double target, int k) {
        // write your code here

        std::priority_queue<Record, std::vector<Record>, RecordComparator> queue;
        traverseTree(root, target, queue);

        std::vector<int> ans;
        for (int i = 0 ; i < k ; ++i) {
            auto rec = queue.top();
            queue.pop();
            ans.push_back(rec.value);
        }

        return ans;
    }

private:
    void traverseTree(
            TreeNode* root,
            double target,
            std::priority_queue<
                Record, std::vector<Record>, RecordComparator>& queue) {

        if (!root) {
            return;
        }

        queue.push(
            Record(abs(static_cast<double>(root->val) - target), root->val));

        traverseTree(root->left, target, queue);
        traverseTree(root->right, target, queue);
    }
};


class Solution2 {
public:
    /**
     * @param root: the given BST
     * @param target: the given target
     * @param k: the given k
     * @return: k values in the BST that are closest to the target
     */
    vector<int> closestKValues(TreeNode * root, double target, int k) {
        // write your code here
        
        /**
         *  target = 19.
         *  k = 3
         * 
         *          20
         *         /  \
         *       15    30  
         *      /  \    \
         *    10    17   35
         *   /  \    \
         *  5   12    18
         * 
         * 
         *  pred: 20 
         *  succ: 15, 17, 18
         * 
         *  20 -> 15 -> 17 -> 18
         */
        
        std::stack<TreeNode*> pred;
        std::stack<TreeNode*> succ;

        auto curr = root;
        while (curr) {
            if (target >= curr->val) {
                pred.push(curr);
                curr = curr->right;
            } else {
                succ.push(curr);
                curr = curr->left;
            }
        }

        std::vector<int> ans;
        for (int i = 0 ; i < k ; ++i) {
            
            if (pred.empty()) {
                ans.push_back(succ.top()->val);
                getSuccessors(succ);
                continue;
            }

            if (succ.empty()) {
                ans.push_back(pred.top()->val);
                getPredecessors(pred);
                continue;
            }

            auto p = pred.top();
            auto s = succ.top();
            if (std::abs(p->val - target) < std::abs(s->val - target)) {
                ans.push_back(p->val);
                getPredecessors(pred);
            } else {
                ans.push_back(s->val);
                getSuccessors(succ);
            }
        }
        
        return ans;
    }

private:
    void getPredecessors(std::stack<TreeNode*>& pred) {
        
        auto curr = pred.top();
        pred.pop();
        
        if (curr->left) {
            curr = curr->left;
            pred.push(curr);
            
            curr = curr->right;
            while (curr) {
                pred.push(curr);
                curr = curr->right;
            }
        }
    }
    
    void getSuccessors(std::stack<TreeNode*>& succ) {
     
        auto curr = succ.top();
        succ.pop();
        
        if (curr->right) {
            curr = curr->right;
            succ.push(curr);
            
            curr = curr->left;
            while (curr) {
                succ.push(curr);
                curr = curr->left;
            }
        }
    }
};
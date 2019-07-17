/**
 * Definition of ExpressionTreeNode:
 * class ExpressionTreeNode {
 * public:
 *     string symbol;
 *     ExpressionTreeNode *left, *right;
 *     ExpressionTreeNode(string symbol) {
 *         this->symbol = symbol;
 *         this->left = this->right = NULL;
 *     }
 * }
 */


class Solution {
public:
    Solution()
      : map({{"*", 2}, {"/", 2}, {"+", 1}, {"-", 1}, {"(", 0}})
    { }

    /*
     * @param expression: A string array
     * @return: The root of expression tree
     */
    ExpressionTreeNode * build(vector<string> &expression) {
        // write your code here

        auto rpn = convertToRPN(expression);
        return buildTree(rpn);
    }

private:
    std::vector<std::string> convertToRPN(const std::vector<std::string>& exp) {

        /**
         * *, /: 2
         * +, -: 1
         * (   : 0
         */

        std::vector<std::string> rpn;
        std::stack<std::string> stk;

        for (const auto& token : exp) {

            if ('0' <= token[0] && token[0] <= '9') {
                rpn.push_back(token);

            } else if (token == "(") {
                stk.push(token);

            } else if (token == ")") {
                while (stk.top() != "(") {
                    rpn.push_back(stk.top());
                    stk.pop();
                }
                stk.pop();

            } else {
                int precedence = map[token];

                while (!stk.empty() && map[stk.top()] >= precedence) {
                    rpn.push_back(stk.top());
                    stk.pop();
                }

                stk.push(token);
            }
        }

        while (!stk.empty()) {
            rpn.push_back(stk.top());
            stk.pop();
        }

        return rpn;
    }


    ExpressionTreeNode* buildTree(const std::vector<std::string>& rpn) {

        std::stack<ExpressionTreeNode*> stk;

        for (const auto& token : rpn) {

            if ('0' <= token[0] && token[0] <= '9') {
                stk.push(new ExpressionTreeNode(token));
            } else {
                auto right = stk.top();
                stk.pop();
                auto left = stk.top();
                stk.pop();

                auto root = new ExpressionTreeNode(token);
                root->left = left;
                root->right = right;

                stk.push(root);
            }
        }

        return !stk.empty() ? stk.top() : nullptr;
    }


    std::unordered_map<std::string, int> map;
};
class Solution {
public:
    Solution()
      : map({{"*", 2}, {"/", 2}, {"+", 1}, {"-", 1}, {"(", 0}})
    { }

    /**
     * @param expression: a list of strings
     * @return: an integer
     */
    int evaluateExpression(vector<string> &expression) {
        // write your code here

        auto rpn = convertToRPN(expression);
        return evaluateRPN(rpn);
    }

private:
    std::vector<std::string> convertToRPN(const std::vector<std::string>& exp) {

        /**
         *  *, /: 2
         *  +, -: 1
         *  (   : 0
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

    int evaluateRPN(const std::vector<std::string>& rpn) {

        std::stack<int> stk;

        for (const auto& token : rpn) {

            if ('0' <= token[0] && token[0] <= '9') {
                stk.push(std::stoi(token));

            } else {
                int op2 = stk.top();
                stk.pop();
                int op1 = stk.top();
                stk.pop();

                int op3;
                if (token == "*") {
                    op3 = op1 * op2;
                } else if (token == "/") {
                    op3 = op1 / op2;
                } else if (token == "+") {
                    op3 = op1 + op2;
                } else if (token == "-") {
                    op3 = op1 - op2;
                }

                stk.push(op3);
            }
        }

        return !stk.empty() ? stk.top() : 0;
    }

    std::unordered_map<std::string, int> map;
};
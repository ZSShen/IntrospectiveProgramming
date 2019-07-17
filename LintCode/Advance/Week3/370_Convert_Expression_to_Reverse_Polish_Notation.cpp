class Solution {
public:
    Solution()
      : map({{"*", 2}, {"/", 2}, {"+", 1}, {"-", 1}, {"(", 0}})
    { }

    /**
     * @param expression: A string array
     * @return: The Reverse Polish notation of this expression
     */
    vector<string> convertToRPN(vector<string> &exp) {
        // write your code here

        /**
         *  *, /: 2,
         *  +, -: 1,
         *  (   : 0
         *
         *      A + B / C * (D + E) - F
         *
         *  Symbol      Stack       Postfix
         *    A                     A
         *    +           +         A
         *    B           +         AB
         *    /           +/        AB
         *    C           +/        ABC
         *    *           +*        ABC/
         *    (           +*(       ABC/
         *    D           +*(       ABC/D
         *    +           +*(+      ABC/D
         *    E           +*(+      ABC/DE
         *    )           +*        ABC/DE+
         *    -           -         ABC/DE+*+
         *    F           -         ABC/DE+*+F
         *                          ABC/DE+*+F-
         */

        std::vector<std::string> rpn;
        std::stack<std::string> stack;

        for (const auto& token : exp) {

            if (token == "(") {
                stack.push(token);

            } else if (token == ")") {
                while (stack.top() != "(") {
                    rpn.push_back(stack.top());
                    stack.pop();
                }
                stack.pop();

            } else if ('0' <= token[0] && token[0] <= '9') {
                rpn.push_back(token);

            } else {

                // Pop the operators that have the higher or the same
                // precedences first, and then push this operator onto the stack.
                int precedence = map[token];
                while (!stack.empty() && precedence <= map[stack.top()]) {
                    rpn.push_back(stack.top());
                    stack.pop();
                }

                stack.push(token);
            }
        }

        while (!stack.empty()) {
            rpn.push_back(stack.top());
            stack.pop();
        }

        return rpn;
    }

private:
    std::unordered_map<std::string, int> map;
};
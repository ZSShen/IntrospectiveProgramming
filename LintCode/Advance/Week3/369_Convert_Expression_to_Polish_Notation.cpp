class Solution {
public:
    Solution()
      : map({{"*", 2}, {"/", 2}, {"+", 1}, {"-", 1}, {"(", 0}})
    { }

    /**
     * @param expression: A string array
     * @return: The Polish notation of this expression
     */
    vector<string> convertToPN(vector<string> &exp) {
        // write your code here

        /**
         *  *, /: 2,
         *  +, -: 1,
         *  (   : 0
         *
         *      A + B / C * (D + E) - F
         *
         *  Symbol      Stack       Prefix
         *    F                       F
         *    -           -           F
         *    )           -)          F
         *    E           -)          FE
         *    +           -)+         FE
         *    D           -)+         FED
         *    (           -           FED+
         *    *           -*          FED+
         *    C           -*          FED+C
         *    /           -* /        FED+C
         *    B           -* /        FED+CB
         *    +           -+          FED+CB/*
         *    A           -+          FED+CB/*A
         *                            FED+CB/*A+-
         *
         *                            -+A* /BC+DEF
         */

        std::stack<std::string> stack;
        std::vector<std::string> pn;

        int n = exp.size();
        for (int i = n - 1 ; i >= 0 ; --i) {
            const auto& token = exp[i];

            if (token == ")") {
                stack.push(token);

            } else if (token == "(") {
                while (stack.top() != ")") {
                    pn.push_back(stack.top());
                    stack.pop();
                }
                stack.pop();

            } else if ('0' <= token[0] && token[1] <= '9') {
                pn.push_back(token);

            } else {

                // Pop the operators that have the higher precedences first,
                // and then push this operator onto the stack.
                int precedence = map[token];
                while (!stack.empty() && precedence < map[stack.top()]) {
                    pn.push_back(stack.top());
                    stack.pop();
                }

                stack.push(token);
            }
        }

        while (!stack.empty()) {
            pn.push_back(stack.top());
            stack.pop();
        }

        std::reverse(pn.begin(), pn.end());
        return pn;
    }

private:
    std::unordered_map<std::string, int> map;
};
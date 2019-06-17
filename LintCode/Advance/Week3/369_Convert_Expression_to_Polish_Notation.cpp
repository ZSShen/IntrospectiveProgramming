class Solution {
public:
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

        int n = exp.size();
        if (n == 0) {
            return {};
        }

        std::unordered_map<std::string, int> map;
        map["*"] = 2;
        map["/"] = 2;
        map["+"] = 1;
        map["-"] = 1;
        map["("] = 0;
        map[")"] = 0;

        std::stack<std::string> stack;
        std::vector<std::string> pn;

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
                int priority = map[token];

                while (!stack.empty() && priority < map[stack.top()]) {
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
};
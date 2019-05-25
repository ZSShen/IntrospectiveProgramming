class Solution {
public:
    /**
     * @param s: A string
     * @return: whether the string is a valid parentheses
     */
    bool isValidParentheses(string &s) {
        // write your code here

        std::stack<char> stack;

        for (char ch : s) {
            switch (ch) {
                case '{':
                case '[':
                case '(':
                    stack.push(ch);
                    break;

                case '}':
                    if (stack.empty() || stack.top() != '{') {
                        return false;
                    }
                    stack.pop();
                    break;

                case ']':
                    if (stack.empty() || stack.top() != '[') {
                        return false;
                    }
                    stack.pop();
                    break;

                case ')':
                    if (stack.empty() || stack.top() != '(') {
                        return false;
                    }
                    stack.pop();
                    break;
            }
        }

        return stack.empty();
    }
};
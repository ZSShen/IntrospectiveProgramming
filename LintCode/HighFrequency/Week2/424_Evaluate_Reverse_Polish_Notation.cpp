class Solution {
public:
    /**
     * @param tokens: The Reverse Polish Notation
     * @return: the value
     */
    int evalRPN(vector<string> &tokens) {
        // write your code here

        std::stack<int> stack;

        for (const auto& token : tokens) {
            if (token == "+") {
                evaluate(stack, '+');
            } else if (token == "-") {
                evaluate(stack, '-');
            } else if (token == "*") {
                evaluate(stack, '*');
            } else if (token == "/") {
                evaluate(stack, '/');
            } else {
                stack.push(std::stoi(token));
            }
        }

        return stack.top();
    }

private:
    void evaluate(std::stack<int>& stack, char op) {

        int op2 = stack.top();
        stack.pop();
        int op1 = stack.top();
        stack.pop();

        int result;
        switch(op) {
            case '+':
                result = op1 + op2;
                break;
            case '-':
                result = op1 - op2;
                break;
            case '*':
                result = op1 * op2;
                break;
            case '/':
                result = op1 / op2;
                break;
        }

        stack.push(result);
    }
};
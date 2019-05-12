class MyQueue {
public:

    MyQueue() {
        // do intialization if necessary
    }

    /*
     * @param element: An integer
     * @return: nothing
     */
    void push(int element) {
        // write your code here

        while (!output.empty()) {
            input.push(output.top());
            output.pop();
        }

        input.push(element);
    }

    /*
     * @return: An integer
     */
    int pop() {
        // write your code here

        while (!input.empty()) {
            output.push(input.top());
            input.pop();
        }

        int top = output.top();
        output.pop();

        return top;
    }

    /*
     * @return: An integer
     */
    int top() {
        // write your code here

        while (!input.empty()) {
            output.push(input.top());
            input.pop();
        }

        return output.top();
    }

private:
    std::stack<int> input;
    std::stack<int> output;
};

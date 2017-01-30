class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() = default;

    /** Push element x onto stack. */
    void push(int x) {
        stack_.push(x);
        int size = stack_.size();
        for (int i = 0 ; i < size - 1 ; ++i) {
            int element = stack_.front();
            stack_.pop();
            stack_.push(element);
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int element = stack_.front();
        stack_.pop();
        return element;
    }

    /** Get the top element. */
    int top() {
        return stack_.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return stack_.empty();
    }

private:
    std::queue<int> stack_;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */